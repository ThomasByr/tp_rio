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
            return receiver_slc(args->target, args->port);
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
            break;
        }
        break;
    }

    return EXIT_FAILURE;
}
