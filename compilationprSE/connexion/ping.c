#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

       



int main(int argc, char const *argv[])
{
    if(argc < 3){
        printf("Erreur : Nombre d'arguments insuffisants \n");
        printf("Usage : %s ip port \n", argv[0]);
        return -1;
    }
    //Declaration de la structure
    struct sockaddr_in serverAddr;
    //Initialisation avec des 0
    memset(&serverAddr, (char)0, sizeof(struct sockaddr_in));

    //Initialisation des membres
    serverAddr.sin_family = AF_INET;// famille d'adresse IPV
    serverAddr.sin_port = htons(atoi(argv[2]));// numero de port converti du format host -> network
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);// transformation de l'adresse IP chaine -> 


    // initialisation du socket
    int tcp_socket_server;
    tcp_socket_server = socket(PF_INET, SOCK_STREAM, 0);
    if(tcp_socket_server == -1){
        perror("Erreur d'initialisation de la socket");
        return -1;
    }

    printf("connexion reussie : \n");
    printf("Adresse IP : %s\n", inet_ntoa(serverAddr.sin_addr));
    printf("Numero de port : %d\n", ntohs(serverAddr.sin_port));

   


    char buf_send[10]="ping";
    char bu_recev=[10]={0};
    while(1){
        i
        recv(tcp_tmp_socket,&buf_rev,4*sizeof(char),0);
        printf("Message recu: %s\n",buf_rev );
        sleep(1);
        send(tcp_tmp_socket,buf_send,strlen(buf_send),0);
        printf("Message envoye :%s\n",buf_send);
       //
    }
     close(tcp_tmp_socket);
    close(tcp_socket_server);

    return 0;
}
