#ifndef ID3HTAGHEADER
#define ID3HTAGHEADER

typedef struct {
  char tag[3];
  char major[1];
  char minor[1];
  char flags[1];
  char size[4];
  int tailletag; /* Decodee bien sur ! */
} tag_header;

int id3_read_tagheader(int fd, tag_header *th);

#endif
