#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define KEY 1

char *utils_xor_str(char *data)
{
	unsigned long len;
	len = utils_strlen(data);
	char *buff = (char *) malloc(len + 1);
	int i;

	for (i = 0; i < len; i++)
	{
		buff[i] = data[i] ^ KEY;
	}
	buff[len] = '\0';

	return buff;
}


int utils_create_report()
{
	FILE *f;
	f = fopen("report.data", "w");
	if (f == NULL)
		return 1;
	fprintf(f, utils_xor_str("BVS REPORT\n"));
	fprintf(f, utils_xor_str("===============================================================\n"));
	fclose(f);
	return 0;
}

int utils_add_data(char *data)
{
	FILE *f;
	f = fopen("report.data", "a");
	if (f == NULL)
		return 1;

	#ifdef DEBUG
		fprintf(f,data);
	#else
		fprintf(f, utils_xor_str(data));
	#endif

	fclose(f);
	return 0;
}

char *utils_syscall(char *cmd)
{
	FILE *fp;
	char tmp[128] = {'\0'};
	char *output = (char *) malloc(128 * sizeof(char));
	char *tmp_ptr;
	int i;

	fp = popen(cmd, "r");

	if (fp == NULL) {
		return NULL;
	}
	memset(output, '\0', 128);

	while (fgets(tmp, 128, fp) != NULL)
	{
		tmp_ptr = realloc(output, (strlen(output) + utils_strlen(tmp)) * sizeof( char *));
		output = tmp_ptr;
		strcat(output, tmp);
	}

	pclose(fp);
	return output;
}

char *utils_strcat(char *s1, char *s2)
{
	int i;

	char *output = (char *) malloc((strlen(s1) + utils_strlen(s2) + 1) * sizeof(char));
	memset(output, '\0', (utils_strlen(s1) + utils_strlen(s2) + 1) * sizeof(char));
	memcpy(output, s1, utils_strlen(s1) + 1);

	for (i = 0; i < utils_strlen(s2); i++)
	{
		output[utils_strlen(s1) + i] = s2[i];
	}

	return output;
}

int utils_strlen(char *s)
{
	int c = 0;

	while (*s++ != 0)
		c++;

	return c;
}