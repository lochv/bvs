#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/utils.h"
#include "get_installed_app.h"

int get_installed_app(char ***app_name,char ***install_status)
{
    *app_name = NULL;
    *install_status = NULL;
    char *tmp = utils_syscall("dpkg --get-selections");
    int pointer = 0, first_pointer, last_pointer;
    int i, n = utils_strlen(tmp);
    int count = 0;
    int column_field = 0;
    for (i = 0; i < n; i++)
        if (tmp[i] > 32 && tmp[i] <= 126)
        {
            if (i == 0 || tmp[i-1] <= 32)
                first_pointer = i;
            last_pointer = i;
        }
        else
        {
            if (tmp[i-1] > 32 && tmp[i-1] <= 126)
            {
                int size = last_pointer - first_pointer + 1;
                if (column_field == 0)
                {
                    count += 1;
                    *app_name = realloc(*app_name, count * sizeof(char*));
                    *(*app_name+count-1) = utils_strndup(tmp + first_pointer,size);
                }
                else if (column_field == 1)
                {
                    *install_status = realloc(*install_status, count * sizeof(char*));
                    *(*install_status+count-1) = utils_strndup(tmp + first_pointer,size);
                }
                column_field ++;
            }
            if (tmp[i] == '\n') column_field = 0;
        }
        return count;
}

char *get_app_version(char *application_name)
{
    char *tmp;
    tmp = utils_strcat("","dpkg -s ");
    tmp = utils_strcat(tmp,application_name);
    tmp = utils_strcat(tmp," | grep '^Version:'");
    tmp = utils_syscall(tmp);
    tmp[utils_strlen(tmp)-1] = 0;
    return tmp+9;
}

void get_install_app_full()
{
    char **app_name;
    char **install_status;
    char **app_version;
    int number_of_app = get_installed_app(&app_name, &install_status);
    app_version = (char **) malloc(number_of_app * sizeof(char*));
    for (int i = 0; i < number_of_app; i++)
    {
        app_version[i] = get_app_version(app_name[i]);
	printf("%s %s\n",app_name[i],app_version[i]);
    }
}

void get_install_app_full_tofile(char *filename)
{
    char **app_name;
    char **install_status;
    int number_of_app = get_installed_app(&app_name, &install_status);
    if (utils_strlen(filename) == 0) filename = utils_strcat("","default-output-file.txt");
    FILE *f = fopen(filename,"w");
    for (int i = 0; i < number_of_app; i++)
    {
        fprintf(f,"%s\t%s\t%s\n",app_name[i],install_status[i],get_app_version(app_name[i]));
    }
    fclose(f);
}
