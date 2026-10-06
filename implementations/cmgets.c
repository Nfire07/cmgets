#include "../headers/cmgets.h"

static bool is_integer(const char *str,long *input_long) {
    if (str == NULL || *str == '\0' || input_long == NULL) {
        return false;
    }

    char *endptr;
    errno = 0; 
    long val = strtol(str, &endptr, 10);

    if (errno == ERANGE) {
        return false;
    }

    if (endptr == str || *endptr != '\0') {
        return false;
    }

    if (val < LONG_MIN || val > LONG_MAX) {
        return false;
    }


    *input_long = val;
    return true; 
}


void* input_reader(size_t esize,int limit,FILE* stream){
    if(limit==0) return NULL;
    
    char buffer[BUFFER_SIZE];
    
    if(limit<0){
        printf("Reading limited at %d\n",BUFFER_SIZE);
    }

    if(!stream || stream==stdin && limit<0){
        fscanf(stdin,"%s",buffer);
    }
    else if(!stream || stream == stdin && limit>0){
        char format[FORMAT_SIZE]; 
        snprintf(format,sizeof(format),"%%%ds",limit);
        fscanf(stdin,format,buffer);
    }

    long returned;

    if(!is_integer(buffer, &returned)){
        printf("Value is picked as it is\n");
    }


    printf("reading a %zu byte integer\n",esize);
    printf("buffer %s\n",buffer);
}
