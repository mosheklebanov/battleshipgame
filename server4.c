#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#define PORT 3055

void cut(char *buffer,int length,char *dest)
{
  int i;
  for(i=0;i<length;i++)
  {
    
  }
}

void error(char *str,int kill)
{
  printf("error in %s \n",str);
  
  if(kill==0)
     printf("%s\n","continueing program");
  else
  {
    printf("%s\n","killing program");
    exit(-1);
  }
}


int main()
{
  int sockfd,sockfd_new,length,users=0,max_users=10;
  struct sockaddr_in host_addr, client_addr;
  socklen_t sin_size;
  pthread_t pool[10];  

  int recv_length=1, yes=1,run=1,i;
  char buffer[1024]; 
  char *str;
  str=buffer;  
  char *msg;

  if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    error("opening sockets",1);

  if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    error("setting socket for tcp",1);

   host_addr.sin_family = AF_INET;
   host_addr.sin_port = htons(PORT); //htons convets x86 little endin to network big endin
   host_addr.sin_addr.s_addr = 0;
   memset(&(host_addr.sin_zero), '\0', 8);  

   if(bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) == -1)
     error("binding socket to port",1); 
 
   if(listen(sockfd,5)==-1)
        error("opeing socket for lissteing",0);


   while(1)
   {
     printf("%s %d\n","lissteing for connections on port: ",PORT);
     sin_size=sizeof(struct sockaddr_in);
     sockfd_new=accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);

     if(sockfd_new==-1)
         error("some one tried and failed to connect",0);
      
     printf("%s\n","remote client accepted"); 
     char *prompt="hello new user\n";
     send(sockfd_new,prompt,strlen(prompt),0);   

     while(1)
     {  
        length=recv(sockfd_new,&buffer,1024,0);
        //system(buffer);
        printf("%s",buffer);    
        memset(str,0,strlen(str));
     }    
    printf("%s\n","remote user disconnected");
    close(sockfd_new);
 
   }
  close(sockfd);
}
