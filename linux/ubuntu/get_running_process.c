#include <stdio.h>
#include <stdlib.h>
#include "utils/utils.h"

char *get_running_process()
{
    char *tmp = utils_syscall("ps axu");
    return tmp;
}

void get_running_process_tofile(char *filename)
{
    if (utils_strlen(filename) == 0) filename = utils_strcat("","default-output-file.txt");
    char *tmp = get_running_process();
    FILE *f = fopen(filename,"w");
    fprintf(f,"%s",tmp);
    fclose(f);
}
