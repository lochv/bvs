#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 1

char *utils_xor_str(char *data)
{
	unsigned int len;
	len = strlen(data);
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

	fprintf(f, utils_xor_str(data));

	fclose(f);
	return 0;
}