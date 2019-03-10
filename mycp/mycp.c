#include <stdio.h>                                               
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
  int src,des,len,i;
  char buf[1024] = {0};
  if(argc < 3)
  {
    printf("./mycp src des");
    exit(1);
  }
  src = open(argv[1], O_RDONLY );
  des = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
  while((i = read(src, buf, sizeof(buf))) > 0) len = i;
  write(des, buf, len);
  close(src);
  close(des);    
}    