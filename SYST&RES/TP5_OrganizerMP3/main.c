  /*
  * extract MP3 tag frames
  * *
  * Author: Gilles MENEZ
  * Created: 2018
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <dirent.h>
  #include <string.h>
  #include <arpa/inet.h>

  #include "util.h"
  #include "id3_tagheader.h"
  #include "id3_frame.h"


  int mp3_get_frame_from_id(int fd,char *id,char contenu[]){
    int nb_lu;
    int i;
    /* Tag Header analysis ---------------------*/
    tag_header th;
    nb_lu = id3_read_tagheader(fd, &th);    
    if (nb_lu != 10) return nb_lu;

    /* Tag frames analysis ---------------------*/
    do {
      nb_lu = id3_read_frame_2(fd, th.tailletag,id,contenu);
    } while ( nb_lu > 0);
    off_t fintag = lseek(fd, 0, SEEK_CUR);

  #if DEBUG
    printf("\nFIN TAG : %lld\n", fintag);
  #endif
    return fintag;
    return 0;
  }

  void text_information_finder(int fd){
    char *id="TIT2";
    char contenu[10000]="";
    int cr=mp3_get_frame_from_id(fd,id,contenu);

    if((cr!=-1)&&(contenu[0]!='\0')){
      contenu[30]='\0';
      printf("%s \n",contenu);
    }
    else{
      printf("%s \n","pas trouvé");
    }
  }

  /*=====================================================*/
  /* Pour comprendre comment parcourir un fichier mp3.

    On rend la position en fin de lecture : normalement 
    on devrait etre en fin de tag.
  */

  off_t mp3_read(int fd){
    int nb_lu;
    int i;

    /* Tag Header analysis ---------------------*/
    tag_header th; /* on va recuperer le header du tag 
          car on en aura besoin pour parcourir les frames */
    nb_lu = id3_read_tagheader(fd, &th);    
    if (nb_lu != 10) return nb_lu;

    /* Tag frames analysis ---------------------*/
    do {
      nb_lu = id3_read_frame(fd, th.tailletag);
    } while ( nb_lu > 0);

    /* Pour verifier ou on est a la fin de la lecture du tag ? -*/
    off_t fintag = lseek(fd, 0, SEEK_CUR);

  #if DEBUG
    //printf("\nFIN TAG : %d\n", fintag);
  #endif
    
    return fintag;
  }

  char** files(char *dir){
    struct dirent *input;
    int taille=0;
    int i=0;
    DIR *ldir;
    ldir = opendir(dir);
    while ((input = readdir(ldir))!=NULL){
      if(strcmp(strrchr(input->d_name,'.'),".mp3")==0){
        taille+=sizeof(input->d_name);
        i++;
      } 
    }
    closedir(ldir);
    ldir = opendir(dir);
    i=0;
    printf("taille : %d\n",taille);
    char **tmp=malloc(taille);
    while ((input = readdir(ldir))!=NULL){
      if(strcmp(strrchr(input->d_name,'.'),".mp3")==0){
        tmp[i]=input->d_name;
        i++;
      } 
    }
    closedir(ldir);
    return tmp;
  }

  void name_album(char *album){
    FILE *f;
    char *filename;
    filename = "MP3/track1.mp3";
    if (! (f = fopen(filename, "r"))){
      perror(filename);
      exit(1);
    }
    int fd = fileno(f); /* Get descriptor from FILE * */
    char *id="TALB";
    int test= mp3_get_frame_from_id(fd ,id ,album);
  }

  void music_name(char *title,char *listfiles,char *album){
    FILE *f;
    char tmp[100];
    strcpy(tmp,album);
    strcat(tmp,"/");
    strcat(tmp,listfiles);
    char *filename;
    filename = tmp;
    /* Ouverture du fichier --------------------*/
    if (! (f = fopen(filename, "r"))){
      perror(filename);
      exit(1);
    }
    int fd = fileno(f); /* Get descriptor from FILE * */
    char *id="TIT2";
    int res = mp3_get_frame_from_id(fd ,id ,title);
    if(res==-1){
      printf("error");
    }
  }

  void track_name(char *track,char *listfiles,char *album){
    FILE *f;
    char tmp[100];
    strcpy(tmp,album);
    strcat(tmp,"/");
    strcat(tmp,listfiles);
    char *filename;
    filename = tmp;
    /* Ouverture du fichier --------------------*/
    if (! (f = fopen(filename, "r"))){
      perror(filename);
      exit(1);
    }
    int fd = fileno(f); /* Get descriptor from FILE * */
    char *id="track";
    int res = mp3_get_frame_from_id(fd ,id ,track);
    if(res==-1){
      printf("error");
    }
  }

  int main(int argc, char *argv[]){
    FILE *f;
    char *filename;
    int nb_lu;
    int i;
    /* Verification de l'appel du programme ----*/
    if (argc != 2){ /* usage -- print usage message and exit */
      fprintf(stderr, "Usage: %s mp3file\n", argv[0]);
      exit(1);
    }
    else
      filename = argv[1];
    /* Ouverture du fichier --------------------*/
    if (! (f = fopen(filename, "r"))){
      perror(filename);
      exit(1);
    }
    int fd = fileno(f); /* Get descriptor from FILE * */
    text_information_finder(fd);

    char* dir = "./MP3";
    char **listfiles =files(dir);
    char name[100];
    char album[100];
    char track[100];
    char title[100];
    char position[100];
    int j=0;

    name_album(album);
    rename("./MP3",album);
    if (mkdir("MP3" ,0777)!=0){
      printf("error création dir");
    }

    while(listfiles[j] != NULL ){
      strcpy(name,album);
      strcat(name,"/");
      music_name(title,listfiles[j],album);
      strcat(name,title);
      strcat(name,"_");//non
      track_name(track,listfiles[j],album);
      strcat(name,track);
      strcpy(position,album);
      strcat(position,"/");
      strcat(position,listfiles[j]);
      strcat(name,".mp3");
      rename(position,name);
      j++;
    }
    printf("\n");
    sync();

    return 0;
  }