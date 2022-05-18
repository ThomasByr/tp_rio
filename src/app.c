#include "app.h"

int exe(const struct io_args *args) {

    switch (args->mode) {
    case server:
        switch (args->protocol) {
        case udp:
            return receiver_udp(args->target, args->port);
            break;
        case tcp:
            return receiver_tcp(args->target, args->port);
            break;
        case slc:
            return 0;
            break;
        }
        break;

    case client:
        switch (args->protocol) {
        case udp:
            return sender_udp(args->target, args->port, args->msg);
            break;
        case tcp:
            return sender_tcp(args->target, args->port, args->msg);
            break;
        case slc:
            return 0;
            break;
        }
        break;
    }

    return EXIT_FAILURE;
}
