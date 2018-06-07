#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "utils/utils.h"

int get_ver(char *ver)
{
	char *tmp;
	tmp = utils_syscall("cmd.exe /c ver");
	memcpy(ver, tmp, utils_strlen(tmp));

	printf("%s\n",ver);
	if (ver == NULL)
		return 1;
	return 0;
}