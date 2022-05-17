#include "app.h"

int exe(const struct io_args *args) {

    switch (args->mode) {
    case server:
        switch (args->protocol) {
        case udp:
            return receiver_udp(args->port);
            break;
        case tcp:
            break;
        }
        break;
    case client:
        switch (args->protocol) {
        case udp:
            return sender_udp(args->target, args->port, args->msg);
            break;
        case tcp:
            break;
        }
        break;
    }
    return EXIT_FAILURE;
}
