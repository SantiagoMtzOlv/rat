#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
    char es[100];
    char le[100];
	
	//printf("primer fase");
    do{
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr("127.0.0.1");
        address.sin_port = 9734;
        len = sizeof(address);

        result = connect(sockfd, (struct sockaddr *)&address, len);
    //printf("segunda fase");
        if(result == -1){
            perror("oops: client3");
            exit(1);
        }
        
        printf("Ingrese una palabra ");
        fgets(es,100,stdin);

        write(sockfd, &es, 100);
        read(sockfd, &le, 100);
        printf("Cliente dice: %s\n", es);
        
            
        printf("Servidor dice: %s\n", le);
        fgets(es,100,stdin);
        write(sockfd, &es, 100);
        //close(sockfd);
    }    
    while(1);    
	return 0;
}
