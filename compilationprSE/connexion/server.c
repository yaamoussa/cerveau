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

    printf("Presentation des donnees de la structure struct : \n");
    printf("Adresse IP : %s\n", inet_ntoa(serverAddr.sin_addr));
    printf("Numero de port : %d\n", ntohs(serverAddr.sin_port));

    // initialisation du socket
    int tcp_socket_server;
    tcp_socket_server = socket(PF_INET, SOCK_STREAM, 0);
    if(tcp_socket_server == -1){
        perror("Erreur d'initialisation de la socket");
        return -1;
    }

    printf("Serveur : Socket ouvert avec succes \n");

    // Attribution d'une adresse au socket
    int resultat = bind(tcp_socket_server, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(resultat == -1){
        perror("Erreur d'initialisation du Bind");
        return -1;
    }

    printf("serveur : Bind execute avec succes\n");

    resultat = listen(tcp_socket_server, 5);
    if(resultat == -1){
        perror("Erreur d'initialisation du listen");
        return -1;
    }

    printf("serveur : Listen execute avec succes\n");
    struct sockaddr_in sockclient;
    int len = sizeof(struct sockaddr_in);
    char buf_c, buf_str[100]={0};

    printf("Serveur en attente de connexion\n");
    while(1){
        int tcp_tmp_socket = accept(tcp_socket_server, (struct sockaddr*) &sockclient, (socklen_t*)&len);

        if(tcp_tmp_socket == -1){
            perror("Erreur d'acceptation de la connexion");
        }

        printf("Connexion d'un nouveau client: %s : %d \n", inet_ntoa(sockclient.sin_addr), ntohs(sockclient.sin_port));
        for (buf_c = 'a'; buf_c < 'z'; ++buf_c)
        {
            send(tcp_tmp_socket, &buf_c, sizeof(char), 0);
        }
        
        close(tcp_tmp_socket);
    }
    close(tcp_socket_server);

    return 0;
}
