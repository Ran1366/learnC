#include <stdio.h>    
#include <errno.h>    
#include <unistd.h>    
#include <sys/types.h>    
#include <sys/stat.h>    
#include <fcntl.h>    
#include <string.h>    
#include <stdlib.h>    
    
#define MSG_TRY "tryagaia\n"    
#define MSG_TIMEOUT "timeout\n"     
int main()    
{                                                                
 //���ն�,���ն�û��������Ӧ�͵�һ���ٴζ�ȡ,�������û    
 //��ȡ�ɹ�,�򷵻صȴ���ʱ,��������,���򽫶���������д��    
 //��׼����ļ�    
 int fd_src,i,len;    
 char buf[10];    
 fd_src = open("/usr/bin/tty", O_RDONLY | O_NONBLOCK);    
 if(fd_src < 0)    
 {    
   perror("open /usr/bin/tty\n");    
   exit(1);    
 } 
  for(i = 0; i < 5; ++i)
 {                        
   len = read(fd_src, buf, 10);
   if(len >= 0)                                                  
   {                   
     break;            
   }
   if(errno != EAGAIN)          
   {                                
     perror("read /usr/bin/tty\n");
     exit(1);
   }                                                         
   sleep(1);                                                
   write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
 }                    
 if(i != 5)       
 {                                                        
   write(STDOUT_FILENO, buf, 10);
 }    
 else                                
 {             
   write(STDOUT_FILENO, MSG_TIMEOUT, strlen(MSG_TIMEOUT));
 }                     
 close(fd_src);           
 return 0;