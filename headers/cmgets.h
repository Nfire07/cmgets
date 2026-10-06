#ifndef CMGETS_H

#define CMGETS_H

#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096
#define FORMAT_SIZE 2048

static void __attribute__((constructor)) init_reader(void){
    setlocale(LC_ALL, "");
}

void* input_reader(size_t esize,int limit,FILE* stream);






#endif
