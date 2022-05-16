#include "lib.h"

noreturn void panic(int syserr, const char *restrict fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    fprintf(stderr, FG_RED);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, RST "\n");
    va_end(ap);

    if (syserr == 1) {
        perror("");
    }

    exit(EXIT_FAILURE);
}
