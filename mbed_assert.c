#include "mbed_assert.h"

#include <stdlib.h>
#include <stdarg.h>
#include "toolchain.h"
#include <stdio.h>

void error(const char* format, ...) {

    va_list arg;
    va_start(arg, format);
    vfprintf(stderr, format, arg);
    va_end(arg);

    exit(1);
}

void mbed_assert_internal(const char *expr, const char *file, int line)
{
    error("mbed assertation failed: %s, file: %s, line %d \n", expr, file, line);
}