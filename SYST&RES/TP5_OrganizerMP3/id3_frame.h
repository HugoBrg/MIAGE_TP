#ifndef ID3HFRAME
#define ID3HFRAME

/*============================================*/
/* Structure du header d'une frame id3        
*/ 

typedef struct { 
  char id[4];	/* = id */
  char size[4];
  char flags[2];
  int tailleframe; /* Taille en LittleEndian */
} frame_header;


int id3_read_frame(int fd, int tagsize);
int id3_read_frame_header(int fd, frame_header *fh, int tagsize);
int id3_read_frame_body(int fd, frame_header *fh);
int id3_read_frame_2(int fd, int tagsize, char *id,char *contenu);
int id3_read_frame_header_2(int fd, frame_header *fh, int tagsize);
int id3_read_frame_body_2(int fd, frame_header *fh,char *id,char *contenu);


#endif