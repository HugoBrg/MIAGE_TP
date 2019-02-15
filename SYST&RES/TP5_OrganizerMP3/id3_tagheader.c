/*
 * extract MP3 tag frames
 * *
 * Author: Gilles MENEZ
 * Created: 2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "util.h"
#include "id3_tagheader.h"
#include "id3_frame.h"

/*--------------------------------------------*/
/* Analyse du header du tag                   
*/
int id3_read_tagheader(int fd, tag_header *th){
  /* Rend la meme information que read(2) mais adapté au "tag header" :
    -1 : erreur pendant la lecture du tag
     0 : plus rien a lire 
     sinon la taille du tag header (ce que l'on vient de lire).
   */

  int nb_alire;
  int nb_lu;
   
  /* read ID3  : 3 bytes .. each ASCII */
  nb_alire = 3;
  nb_lu  = read_error(fd, th->tag, nb_alire, "Read TAG");
  if (nb_lu != nb_alire) return nb_lu;

#if DEBUG
  printf_buff(th->tag, nb_alire, "%c", "TAG");
#endif
  
  /* read major : 1 byte .. raw */
  nb_alire = 1;
  nb_lu  = read_error(fd, th->major, nb_alire, "Read Version Maj");
  if (nb_lu != nb_alire) return nb_lu;
  
#if DEBUG
  printf_buff(th->major, nb_alire, "%x", "\tMAJOR");
#endif
  
  /* read minor : 1 byte .. raw */
  nb_alire = 1;
  nb_lu  = read_error(fd, th->minor, nb_alire, "Read Version Min");
  if (nb_lu != nb_alire) return nb_lu;

#if DEBUG
    printf_buff(th->minor, nb_alire, "%x", "\tMINOR");
#endif
  
  /* read flags : 1 byte .. raw */
  nb_alire = 1;
  nb_lu = read_error(fd, th->flags, nb_alire, "Read FLAGS");
  if (nb_lu != nb_alire)  return nb_lu;

#if DEBUG
  printf_buff(th->flags, nb_alire, "%x", "\tFLAGS");
#endif
  
  /* read size of the tag : 4 byte .. special code */
  nb_alire = 4;
  nb_lu = read_error(fd, th->size, nb_alire, "Read SIZE");
  if (nb_lu != nb_alire) return nb_lu;
		   
  /* For test : info.size[0] = 0x00; info.size[1] = 0x00; info.size[2]
  = 0x02; info.size[3] = 0x01;*/
  th->tailletag = decode_taille(th->size);

#if DEBUG
  printf("\n\tTag size : %d\n", th->tailletag);
#endif
  
  return 10; /* sinon on serait sorti avant ! */
}
