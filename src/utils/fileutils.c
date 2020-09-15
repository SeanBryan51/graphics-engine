
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "fileutils.h"

char *read_file(char *filepath) {

    FILE *file = fopen(filepath, "rt");
    
    assert(file != NULL);

    fseek(file, 0, SEEK_END);
    unsigned long length = ftell(file);
    char *data = (char *) calloc(length + 1, sizeof(char));
    fseek(file, 0, SEEK_SET);
    fread(data, 1, length, file);
    fclose(file);

    return data;
}
