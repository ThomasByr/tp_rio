#include "receiver-udp.h"

int receiver_udp(int port) {
    int sockfd;             // descripteur de socket
    char buf[BUFLEN] = {0}; // espace necessaire pour stocker le message recu

    // taille d'une structure sockaddr_in utile pour la fonction recvfrom
    socklen_t fromlen = sizeof(struct sockaddr_in);

    struct sockaddr_in my_addr; // structure d'adresse qui contiendra les param
                                // reseaux du recepteur
    struct sockaddr_in client;  // structure d'adresse qui contiendra les param
                                // reseaux de l'expediteur

    // creation de la socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // initialisation de la structure d'adresse du recepteur (pg local)

    // famille d'adresse
    my_addr.sin_family = AF_INET;

    // recuperation du port du recepteur
    my_addr.sin_port = htons(port);

    // adresse IPv4 du recepteur
    inet_aton(IP_RECEIVER, &(my_addr.sin_addr));

    // association de la socket et des param reseaux du recepteur
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr)) != 0) {
        perror("erreur lors de l'appel a bind -> ");
        exit(-2);
    }

    debug(1, "Receiver UDP listening on port %d\n", port);

    // reception de la chaine de caracteres
    if (recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr *restrict)&client,
                 &fromlen) == -1) {
        perror("erreur de reception -> ");
        exit(-3);
    }

    // affichage de la chaine de caracteres recue
    info(1, "Received: %s\n", buf);

    // fermeture de la socket
    close(sockfd);

    return 0;
}
