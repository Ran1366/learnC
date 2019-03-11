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
 //读终端,若终端没有立即响应就等一秒再次读取,若五秒后还没    
 //读取成功,则返回等待超时,结束程序,否则将读到的内容写入    
 //标准输出文件    
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