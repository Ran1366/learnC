#include <fcntl.h>                                               
#include <unistd.h>    
#include <stdio.h>                         
#include <sys/types.h>    
#include <sys/stat.h>                        
#include <string.h>    
#include <errno.h>        
#include <stdlib.h>    
       
int main()    
{                                     
  //读输入文件STDIN_FILENO,将其先设为非阻塞,使用轮询机制    
  char buf[10];    
  int n;               
  int flags;    
  flags = fcntl(STDIN_FILENO, F_GETFL);                       
  flags |= O_NONBLOCK;    
  if(fcntl(STDIN_FILENO, F_SETFL, flags))    
  {                      
    perror("fcntl\n");    
    exit(1);    
  }                                 
tryagain:    
  n = read(STDIN_FILENO, buf, 10);
    if(n < 0)                                
  {                       
    if(n == EAGAIN)                          
    {                                                            
      write(STDOUT_FILENO, "tryagin", strlen("tryagain"));
      goto tryagain;   
    }  
    perror("read\n");
    exit(1);                          
  }                                                         
  write(STDOUT_FILENO, buf, 10);
  return 0;            
} 