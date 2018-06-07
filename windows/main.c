#include <stdio.h>
#include <malloc.h>
#include "utils/utils.h"
#include "get_installed_app.h"

int main(int argc, char const *argv[])
{
	char *version = utils_syscall("cmd.exe /c ver");

	if (version == NULL)
	{
		fprintf(stderr, "[-] Version not found!");
		return 1;
	}
	fprintf(stdout,"[+] Detect version: %s\n", version);

	if(utils_create_report())
	{
		fprintf(stderr, "Cannot create report file!");
		return 1;
	}
	fprintf(stdout,"[+] Create report file success!\n");

	get_installed_app_via_hklm();
	get_installed_app_via_hkcu();

	fprintf(stdout,"[+] Done!\n");
	return 0;
}