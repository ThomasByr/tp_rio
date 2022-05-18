#include "receiver-udp.h"

int receiver_udp(char *target, int port) {
    int sockfd;             // socket file descriptor
    char buf[BUFLEN] = {0}; // buffer

    // size of the address structure (used by `recvfrom`)
    socklen_t fromlen = sizeof(struct sockaddr_in);

    struct sockaddr_in my_addr; // address structure of the receiver
    struct sockaddr_in client;  // address structure of the sender

    // socket init
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // address family
    my_addr.sin_family = AF_INET;

    // port of the receiver
    my_addr.sin_port = htons(port);

    // IPv4 address of the receiver
    inet_aton(target, &(my_addr.sin_addr));

    // association of the socket and the address structure
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr)) != 0) {
        panic(1, "bind failure");
    }

    debug(1, "Receiver UDP listening on port %d\n", port);

    // reception of the message
    if (recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr *restrict)&client,
                 &fromlen) == -1) {
        panic(1, "recvfrom failure");
    }

    // print
    info(1, "Received: %s\n", buf);

    // closing socket
    close(sockfd);

    return EXIT_SUCCESS;
}
