#include <string.h>
#include "utils/utils.h"
#include <stdlib.h>
#include <stdio.h>

char *get_version(char *cmd_output)
{
    char cmd_type[16];
    strcpy(cmd_type,"Description:\0");
    int i;
    int check_type = 1;
    for (i = 0; i < utils_strlen(cmd_type); i++)
    {
        if (cmd_type[i] != cmd_output[i])
        {
            check_type = 0;
            break;
        }
    }
    if (check_type)
    {
        for (; i < utils_strlen(cmd_output); i++)
            if (cmd_output[i] != '\t')
                return cmd_output+i;
    } else
    return cmd_output;
}
