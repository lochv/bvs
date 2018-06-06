#include "get_version.h"
#include <stdio.h>
#include <malloc.h>
#include "utils/utils.h"

int main(int argc, char const *argv[])
{
	char *ver = (char *) malloc(64);

	if (get_ver(ver))
	{
		fprintf(stderr, "Version not found!");
		return 1;
	}

	#ifdef DEBUG
		printf("Version: %s\n", ver);
	#endif

	if(utils_create_report())
	{
		fprintf(stderr, "Cannot create report!");
		return 1;
	}
	return 0;
}