#include <stdio.h>    
#include <sys/types.h>    
#include <sys/stat.h>    
#include <unistd.h>    
#include <fcntl.h>    
#include <string.h>    
    
int main()    
{    
  int len;    
  char buf[1024] = {0};    
  len = read(STDIN_FILENO, buf, sizeof(buf));    
  write(STDOUT_FILENO, buf, len);    
  return 0;                                                      
}