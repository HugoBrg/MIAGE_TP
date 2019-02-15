  /*
  * extract MP3 tag frames
  * *
  * Author: Gilles MENEZ
  * Created: 2018
  */
  #include <stdio.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <assert.h>
  #include <string.h>
  #include <ctype.h>
  #include <arpa/inet.h>

  #include "util.h"
  #include "id3_tagheader.h"
  #include "id3_frame.h"

  /*#include "genre.h" /* definit la variable "genre" pour 
            les frames "TCON" */

  /*============================================*/
  /* Analyse d'un header de frame :
    => On recupere les infos via le parametre fh
    => qui  doit avoir ete allou�e

    On suppose la frame non corrompue => elle est conforme
    dans le fichier ! 
    (cad le fichier ne s'arrete pas au milieu de la trame !)
  */
  int id3_read_frame_header(int fd, frame_header *fh, int tagsize){
    /* 
      On va remplir fh (c'est pour cela qu'on a un pointeur.
      
      On a besoin de tagsize pour sauter le padding si des fois ce
      n'est pas une frame ?

      Rend la meme information que read(2) mais adapt� au "frame header" :
      -1 : erreur pendant la lecture du header
      0 : plus rien a lire 
      sinon la taille du frame header.
    */
    int nb_alire; /* Nb d'octets � lire */
    int nb_lu;

    /*=== Lecture de l'ID -----------------------------------*/ 
    nb_alire = 1;
    nb_lu = read_error(fd, fh->id, nb_alire, "Read Frame ID (1)");
    if (nb_lu != nb_alire) return nb_lu;

    /* et si on etait dans le padding ? */
    if (fh->id[0] == 0){ /* faut sauter le padding */
      lseek(fd, (tagsize) + 10, SEEK_SET);
      return 0; /* et dire qu'il n'y a plus rien a lire */
    }
    
    nb_alire = 3;
    nb_lu = read_error(fd, &(fh->id[1]), nb_alire, "Read Frame ID (3)");
    if (nb_lu != nb_alire) return nb_lu;
    
  #if DEBUG
    printf_buff(fh->id, nb_alire+1, "%c", "ID");
  #endif
    
    /*=== Lecture de la taille de la frame "POST HEADER" ---*/ 
    nb_alire = 4;
    nb_lu = read_error(fd, fh->size, nb_alire, "Read Frame Size");
    if (nb_lu != nb_alire) return nb_lu;

    /* fh->size en BigEndian ... 
      Pas de chance Intel est LittleEndian */
    fh->tailleframe = decode_taille(fh->size);
    //  fh->tailleframe = htonl(*((int *)fh->size));

  #if DEBUG
    printf_buff(fh->size, nb_alire, "%x", "SIZE");
    printf("\n\tSIZE  : %d",fh->tailleframe);
    /* printf("\n\tENDIANESS PB! = %d",(int *)(fh->size));*/
  #endif
    
    /*=== Lecture des flags --------------------------------*/ 
    nb_alire = 2;  
    nb_lu = read_error(fd, fh->flags, nb_alire, "Read Frame Flags");
    if (nb_lu != nb_alire) return nb_lu;

  #if DEBUG
    printf_buff(fh->flags, nb_alire, "%x","\tFLAGS");
  #endif

    return 10; /* Si on en est l� c'est que c'est OK */
  }


  /*============================================*/
  /* Analyse d'un body de frame      
  * On a besoin de fh, si on veut s'interesser au type de la frame !
  * Ant : fd "is" on the byte just after the frame header. 
  */

  int id3_read_frame_body(int fd, frame_header *fh){
    int nb_alire; /* Nb d'octets � lire */
    int nb_lu;

    /* Pour info ... fh->id[0] contient la premiere lettre
      de l'identificateur de la trame 
      et bien sur fh->id contient l'id MAIS ce n'est pas une string ! */
    if(fh->id[0]=='T'){
      printf(" Type : Text Identificateur\n");
    }

    /* Pour l'instant, on se contente de sauter les octets de la frame */
    lseek(fd, fh->tailleframe, SEEK_CUR);
    nb_lu = fh->tailleframe; /* Size of frame */
    
    return nb_lu;
  }


  /*============================================*/
  /* Analyse d'une frame                        
  */

  int id3_read_frame(int fd, int tagsize){

    frame_header fh; /* On recupere le frame header*/
    int nb_lu;
    
    /* Analyse du header de la frame */
    nb_lu = id3_read_frame_header(fd, &fh, tagsize);
    if (nb_lu != 10)
      return nb_lu;
    
    /* Body de la frame */
    nb_lu = id3_read_frame_body(fd, &fh);

    return (nb_lu);
  }

  /*============================================*/
  int id3_read_frame_header_2(int fd, frame_header *fh, int tagsize){
    /* 
      On va remplir fh (c'est pour cela qu'on a un pointeur.
      
      On a besoin de tagsize pour sauter le padding si des fois ce
      n'est pas une frame ?

      Rend la meme information que read(2) mais adapt� au "frame header" :
      -1 : erreur pendant la lecture du header
      0 : plus rien a lire 
      sinon la taille du frame header.
    */
    int nb_alire; /* Nb d'octets � lire */
    int nb_lu;

    /*=== Lecture de l'ID -----------------------------------*/ 
    nb_alire = 1;
    nb_lu = read_error(fd, fh->id, nb_alire, "Read Frame ID (1)");
    if (nb_lu != nb_alire) return nb_lu;

    /* et si on etait dans le padding ? */
    if (fh->id[0] == 0){ /* faut sauter le padding, on se place apr�s le padding */
      lseek(fd, (tagsize) + 10, SEEK_SET);
      return 0; /* et dire qu'il n'y a plus rien a lire */
    }
    
    nb_alire = 3;
    nb_lu = read_error(fd, &(fh->id[1]), nb_alire, "Read Frame ID (3)");
    if (nb_lu != nb_alire) return nb_lu;
    
  #if DEBUG
    printf_buff(fh->id, nb_alire+1, "%c", "ID");
  #endif
    
    /*=== Lecture de la taille de la frame "POST HEADER" ---*/ 
    nb_alire = 4;
    nb_lu = read_error(fd, fh->size, nb_alire, "Read Frame Size");
    if (nb_lu != nb_alire) return nb_lu;

    /* fh->size en BigEndian ... 
      Pas de chance Intel est LittleEndian */
    fh->tailleframe = decode_taille(fh->size);
    //  fh->tailleframe = htonl(*((int *)fh->size));

  #if DEBUG
    printf_buff(fh->size, nb_alire, "%x", "SIZE");
    printf("\n\tSIZE  : %d",fh->tailleframe);
    /* printf("\n\tENDIANESS PB! = %d",(int *)(fh->size));*/
  #endif
    
    /*=== Lecture des flags --------------------------------*/ 
    nb_alire = 2;  
    nb_lu = read_error(fd, fh->flags, nb_alire, "Read Frame Flags");
    if (nb_lu != nb_alire) return nb_lu;

  #if DEBUG
    printf_buff(fh->flags, nb_alire, "%x","\tFLAGS");
  #endif

    return 10; /* Si on en est l� c'est que c'est OK */
  }


  /*============================================*/
  /* Analyse d'un body de frame      
  * On a besoin de fh, si on veut s'interesser au type de la frame !
  * Ant : fd "is" on the byte just after the frame header. 
  */

  int id3_read_frame_body_2(int fd, frame_header *fh,char *id,char *contenu){
    int nb_alire; /* Nb d'octets � lire */
    int nb_lu;
    if(fh->id[0]=='T'){	
      if(strncmp(fh->id,id,4)==0) {
        printf("\n");
        nb_lu = read_error(fd, contenu, fh->tailleframe, "Lecture body");
        if (nb_lu != nb_alire)   
          return nb_lu;
      }
    }
    lseek(fd, fh->tailleframe, SEEK_CUR);
    nb_lu = fh->tailleframe; /* Size of frame */
    
    return nb_lu;
  }

  int id3_read_frame_2(int fd, int tagsize, char *id, char *contenu){

    frame_header fh; /* On recupere le frame header*/
    int nb_lu;
    
    /* Analyse du header de la frame */
    nb_lu = id3_read_frame_header_2(fd, &fh, tagsize);
    if (nb_lu != 10)
      return nb_lu;
    
    /* Body de la frame */
    nb_lu = id3_read_frame_body_2(fd, &fh,id,contenu);

    return (nb_lu);
  }
