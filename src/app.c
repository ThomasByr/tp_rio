#include "app.h"

int exe(const struct io_args *args) {

    switch (args->mode) {
    case server:
        switch (args->protocol) {
        case udp:
            break;
        case tcp:
            break;
        }
    case client:
        switch (args->protocol) {
        case udp:
            break;
        case tcp:
            break;
        }
    }
}
