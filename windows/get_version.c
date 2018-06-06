#include <stdio.h>
#include <stdlib.h>


int get_ver(char *ver)
{
	FILE *fp;
	char tmp[256];
	int i;
	fp = popen("cmd.exe /c ver", "r");

	if (fp == NULL) {
		return 1;
	}

	while (fgets(tmp, 1023, fp) != NULL);

	for (i = 18; i < sizeof(tmp); i++)
	{
		if (tmp[i] == ' ')
			break;
		ver[i - 18] = tmp[i];
	}

	pclose(fp);

	return 0;
}