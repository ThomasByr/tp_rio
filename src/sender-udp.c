#include "sender-udp.h"

int sender_udp(int target, int port, const char *msg) {
    int sockfd;              // descripteur de socket
    struct sockaddr_in dest; // structure d'adresse qui contiendra les
                             // parametres reseaux du destinataire

    // creation de la socket
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // initialisation de la structure d'adresse du destinataire :

    // famille d'adresse
    dest.sin_family = AF_INET;

    // adresse IPv4 du destinataire
    inet_aton("192.168.0.1", &(dest.sin_addr));

    // port du destinataire
    dest.sin_port = port;

    // envoi de la chaine
    if (sendto(sockfd, &msg, sizeof(msg), 0, &dest.sin_addr,
               sizeof(dest.sin_addr)) == -1) {
        perror("erreur a l'appel de la fonction sendto -> ");
        exit(-2);
    }

    // fermeture de la socket
    close(sockfd);

    return 0;
}
