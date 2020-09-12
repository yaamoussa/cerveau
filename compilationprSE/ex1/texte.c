/** Sinon, si nous sommes sous Linux */
 
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
 
    /** Define, qui nous serviront par la suite **/
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close (s)
 
    /** De même */
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
 
 
/** On inclut les fichiers standards **/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
 
#define PORT    23
 
int main(int argc, char *argv[])
{
    FILE *txt1      = NULL;
    FILE *txt2      = NULL;
 
    int poidsTxt1 = 0; /** pareil **/
    int poidsTxt2 = 0; /** pareil **/
 
    int caractereLu = 0;
    int dataSend = 0;
    int dataRead = 0;
    int totalSend = 0;
    int i = 0;
 
    /** Socket et contexte d'adressage du server **/
    SOCKET sock = 0;
    SOCKADDR_IN sin;
 
    /** Socket et contexte d'adressage du client **/
    SOCKET csock = 0;
    SOCKADDR_IN csin;
    socklen_t recsize = sizeof(csin);
 
    int sock_err = 0;
    char bufferTxt1[1024] = "";
    char bufferTxt2[1024] = "";
 
    txt1 = fopen("test.txt", "r");
    txt2 = fopen("test2.txt", "r")
 
    if(txt1 == NULL || txt2 == NULL)
    {
        perror("Imposssible d'ouvrir les fichier ");
        exit(errno);
    }
 
    /** calcul du poids des fichiers txt **/
    /** test.txt **/
 
    while((caractereLu = fgetc(txt1)) != EOF)
    {
        bufferTxt1[i] = caractereLu;
        poidsTxt1++;
        //printf("buffer[%d] = %c\n", i, bufferTxt1[i]);
        i++;
    }
 
    printf("le poids du fichier txt1 est de %d octets.\n\n\n", poidsTxt1);
 
    /** test2.txt **/
     while((caractereLu = fgetc(txt2)) != EOF)
    {
        bufferTxt2[i] = caractereLu;
        poidsTxt2++;
        //printf("buffer[%d] = %c\n", i, bufferTxt2[i]);
        i++;
    }
 
    printf("le poids du fichier txt2 est de %d octets.\n", poidsTxt2);
 
    fclose(txt1);
    fclose(txt2);
 
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == INVALID_SOCKET)
    {
        perror("Can't create the socket file descriptor ");
        exit(errno);
    }
 
    printf("\nLa socket %d est maintenant ouverte en mode TCP/IP.\n", sock);
 
    /** configuration, contexte d'adressage server **/
    sin.sin_addr.s_addr     = htonl(INADDR_ANY);
    sin.sin_family          = AF_INET;
    sin.sin_port            = htons(PORT);
 
    sock_err = bind(sock, (SOCKADDR *)&sin, sizeof(sin));
 
    /** Si la socket fonctionne **/
    if(sock_err != SOCKET_ERROR)
    {
        sock_err = listen(sock, 5);
        printf("\nListage du port %d....\n", PORT);
 
        if(sock_err != SOCKET_ERROR)
        {
            printf("\nPatientez pendant q'un client se connecte sur le port %d.....\n\n", PORT);
 
            csock = accept(sock, (SOCKADDR *)&csin, &recsize);
            if(csock == -1)
            {
                perror("ERROR accept() ");
                exit(errno);
            }
            printf("Un client se connecte avec la socket %d depuis %s:%d.\n\n", csock,
                                                                            inet_ntoa(csin.sin_addr),
                                                                            htons(csin.sin_port));
            /** Envoie du poid du 1er fichier texte **/
            dataSend = send(csock, (char *)&poidsTxt1, sizeof(poidsTxt1), 0);
            if(dataSend < 0)
            {
                perror("Failed to send weight of the first texte file.\n");
                exit(errno);
            }
 
            /** printf("Envoie du poid du fichier txt1 soit %d bytes/octets.\n\n", poidsTxt1); **/
 
            /** Envoie du 1 er fichier txt **/
            txt1 = fopen("test.txt", "rb");
            if(txt1 == NULL)
            {
                perror("Imposssible d'ouvrir les fichier ");
                exit(errno);
            }
            i = 0;
            do
            {
                dataRead = fread(bufferTxt1, sizeof(bufferTxt1), 1, txt1);
                dataSend = send(csock, bufferTxt1, sizeof(caractereLu), 0);
 
                //printf("envoie de %d bytes/octets\n", dataSend);
 
                if(dataSend == SOCKET_ERROR)
                {
                    perror("send() ");
                    exit(errno);
                }
 
                if(totalSend == 28)
                    dataSend = send(csock, bufferTxt1, 1, 0);
 
                totalSend += dataSend;
 
                printf("total send = %d\n", totalSend);
 
                if(totalSend > poidsTxt1)
                    break;
 
            }while(totalSend < poidsTxt1);
 
        }
 
        shutdown(csock, 2);
        printf("Fermeture de la connection ...\n");
    }
 
    closesocket(sock);
    printf("Fermeture socket server ...\n");
 
    closesocket(csock);
    printf("Fermeture socket client ...\n");
 
 
    return EXIT_SUCCESS;
 
}