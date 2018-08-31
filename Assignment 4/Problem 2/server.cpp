#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     time_t t=time(NULL);
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
      newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
      if (newsockfd < 0) 
          error("ERROR on accept");
        //int pid=fork();
        bzero(buffer,256);
        // n = read(newsockfd,buffer,255);
        // //char temp[256];
        // for(int i=0;i<256;i++){
        //   if(buffer[i]>=97&&buffer[i]<=122){
        //   buffer[i]-=32;
        // }

      
      //if (n < 0) error("ERROR reading from socket");
      //printf("Here is the message: %s\n",buffer);
      n = write(newsockfd,ctime(&t),255);
      printf("%d\n",n );
      if (n < 0) error("ERROR writing to socket");
      close(newsockfd);
        
     
     
     return 0; 
}
