#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

/*  Write "n" bytes to a descriptor.  *//
ssize_t writen(int fd, const void *vptr, size_t n){
  size_t		nleft;
  ssize_t		nwritten;
  const char	*ptr;
  
  ptr = vptr;
  nleft = n;
  while (nleft > 0) {
    if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
      if (errno == EINTR)
	nwritten = 0;		/* and call write() again */
      else
	return(-1);	       /* error */
    }
    
    nleft -= nwritten;       /* Decrease nleft */
    ptr   += nwritten;
  }
  return(n);
} /* end writen */

void Writen(int fd, void *ptr, size_t nbytes){
  if (writen(fd, ptr, nbytes) != nbytes)
    perror("writen error");
}
