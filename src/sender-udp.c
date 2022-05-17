#include "sender-udp.h"

int sender_udp(char *target, int port, const char *msg) {
    int sockfd;              // socket file descriptor
    struct sockaddr_in dest; // address structure of the target

    // socket init
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // address family
    dest.sin_family = AF_INET;

    // IPv4 dest address
    inet_aton(target, &(dest.sin_addr));

    // dest port
    dest.sin_port = htons(port);

    // send msg
    if (sendto(sockfd, msg, BUFLEN, 0, (const struct sockaddr *)&dest,
               sizeof(dest)) == -1) {
        panic(1, "sendto failure");
    }

    debug(1, "Sent msg: %s\n", msg);
    debug(0, "\t-> to %s:%d\n", target, port);

    // closing socket
    close(sockfd);

    return EXIT_SUCCESS;
}
