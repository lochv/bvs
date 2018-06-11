#include <stdio.h>
#include <malloc.h>
#include "utils/utils.h"
#include "get_installed_app.h"
#include "ubuntu_special.h"

int main(int argc, char const *argv[])
{
	char *version = get_version(utils_syscall("lsb_release -d"));
        puts(version);
	if (version == NULL)
	{
		fprintf(stderr, "[-] Version not found!");
		return 1;
	}
	fprintf(stdout, "[+] Detect version: %s\n", version);

	get_install_app_full_tofile("");

	if(utils_create_report())
	{
		fprintf(stderr, "%s", "Cannot create report file!");
		return 1;
	}
	fprintf(stdout, "%s", "[+] Create report file success!\n");

	fprintf(stdout, "%s", "[+] Done!\n");
	return 0;
}
