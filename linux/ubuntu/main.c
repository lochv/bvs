#include <stdio.h>
#include <malloc.h>
#include "utils/utils.h"
#include "get_installed_app.h"
#include "get_running_process.h"
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

	get_install_app_full_tofile("application_installed.data");
	fprintf(stdout, "[+] Finish retrieve application installed list\n");
	get_running_process_tofile("running_process.data");
	fprintf(stdout, "[+] Finish retrieve running process list\n");

	if(utils_create_report())
	{
		fprintf(stderr, "%s", "Cannot create report file!");
		return 1;
	}
	fprintf(stdout, "%s", "[+] Create report file success!\n");

	fprintf(stdout, "%s", "[+] Done!\n");
	return 0;
}
