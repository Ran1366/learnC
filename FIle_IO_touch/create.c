#include <stdio.h>                                               
#include <sys/types.h>    
#include <sys/stat.h>    
#include <fcntl.h>    
#include <stdlib.h>    
    
int main(int argc, char *argv[])    
{    
  int fd;
  if(argc < 2)    
  {    
    printf("./creat need filename\n");    
    exit(1);    
  }    
  fd = open(argv[1], O_CREAT, 0666);    
  printf("fd = %d\n", fd);    
  return 0;    
}