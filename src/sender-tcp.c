#include "sender-tcp.h"

int sender_tcp(char *target, int port, const char *msg) {
    int sockfd;              // descripteur de socket
    struct sockaddr_in dest; // structure d'adresse qui contiendra les
                             // parametres reseaux du destinataire

    // creation de la socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // initialisation de la structure d'adresse du destinataire :

    // famille d'adresse
    dest.sin_family = AF_INET;

    // adresse IPv4 du destinataire
    inet_aton(target, &(dest.sin_addr));

    // port du destinataire
    dest.sin_port = htons(port);

    // envoi de la chaine
    if (connect(sockfd, (struct sockaddr *)&dest, sizeof(dest)) == -1) {
        perror("erreur a l'appel de la fonction connect -> ");
        exit(-2);
    }

    // envoi de la chaine
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("erreur a l'appel de la fonction send -> ");
        exit(-3);
    }

    debug(1, "Sent msg: %s\n", msg);
    debug(0, "\t-> to %s:%d\n", target, port);

    // fermeture de la socket
    close(sockfd);

    return 0;
}