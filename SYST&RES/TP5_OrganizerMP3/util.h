
#ifndef UTILH
#define UTILH

int read_error(int fd, char *buff, int nb_alire, const char *msg);
void printf_buff(char *buf, int nb, char *format, char *label);
int decode_taille(char t[4]);
  
#define DEBUG 1

#endif
