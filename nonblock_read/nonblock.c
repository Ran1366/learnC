#include <stdio.h>                                               
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>    
#include <sys/types.h>                                 
#include <string.h>
#include <stdlib.h>
#include <errno.h>                  
                
int main()
{           
  int fd,n;                 
  char buf[10] = {0};
  fd = open("/usr/bin/tty", O_RDONLY | O_NONBLOCK);
  if(fd < 0)               
  {      
    perror("opne /usr/bin/tty");
    exit(1);                                                
  }
tryagin: 
  n = read(fd, buf, 10);            
  if(n < 0)     
  {    
    if(errno == EAGAIN)
    {             
      sleep(1);          
      write(STDIN_FILENO, "tryagin", strlen("tryagin"));
      goto tryagin;                                              
    }              
    perror("read /usr/bin/tty");    
    exit(1);    
  }       
  write(STDOUT_FILENO, buf, n);
  close(fd);                
  return 0;          
}    