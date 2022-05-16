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

void debug(int first, const char *restrict fmt, ...) {
#ifndef DEBUG
    (void)first;
    (void)fmt;
#else
    va_list ap;

    va_start(ap, fmt);
    if (first) {
        fprintf(stdout, FG_GRN "  DEBUG: " RST);
    }
    vfprintf(stdout, fmt, ap);
    va_end(ap);

    int n = fflush(stdout);
    if (n == EOF) {
        panic(1, "fflush failure");
    }
#endif
}

void info(int first, const char *restrict fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    if (first) {
        fprintf(stdout, FG_BLU "\n   INFO: " RST);
    }
    vfprintf(stdout, fmt, ap);
    va_end(ap);
    int n = fflush(stdout);
    if (n == EOF) {
        panic(1, "fflush failure");
    }
}

void snprintf_s(char *restrict str, size_t size, const char *restrict fmt,
                ...) {
    int n;
    va_list ap;

    va_start(ap, fmt);
    n = vsnprintf(str, size, fmt, ap);
    va_end(ap);

    if (n < 0) {
        panic(1, "vsnprintf failure");
    }
    if ((size_t)n >= size) {
        panic(1, "format string too long");
    }
}
