#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

/*------------------------------------------
 * Read "n" bytes from a descriptor fd.
 * Bytes are stored in vptr              
 */
ssize_t readn(int fd, void *vptr, size_t n){
  size_t	nleft;
  ssize_t	nread;
  char	*ptr;
  ptr = vptr;
  nleft = n;
  while (nleft > 0) {
    if ( (nread = read(fd, ptr, nleft)) < 0) {
      if (errno == EINTR)
	nread = 0;	      /* and call read() again */
      else
	return(-1);           /* Big Pb */
    } 
    else if (nread == 0)
      break;		      /* EOF */
    
    nleft -= nread;           /* Decrease nleft */
    ptr   += nread;
  }
  return (n - nleft);	      /* return number of byte read >= 0 */
} /* end readn */

/* Same with perror if read failed  -----------*/
ssize_t Readn(int fd, void *ptr, size_t nbytes){
  ssize_t		n;
  if ( (n = readn(fd, ptr, nbytes)) < 0)
    perror("readn error");
  return(n);
} /* end Readn */
