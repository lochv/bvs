#include <stdio.h>
#include "utils/utils.h"
#include <stdlib.h>
#include <string.h>

#define REG_PATH_HKLM32 "HKEY_LOCAL_MACHINE\\Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall"
#define REG_PATH_HKLM "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall"

#define REG_PATH_HKCU32 "HKEY_CURRENT_USER\\Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall"
#define REG_PATH_HKCU "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall"


int get_installed_app_via_hklm()
{
	char *tmp;
	char line[512];
	int i, j = 0;

	tmp = utils_syscall(utils_strcat("reg query ", REG_PATH_HKLM));
	memset(line, '\0', 512);
	for (i = 0; i < strlen(tmp); i++)
	{
		if (tmp[i] == '\n'){
			j = 0;
			if (line[0] != '\0')
			{
				utils_add_data(utils_syscall(utils_strcat("reg query \"", utils_strcat(line, "\""))));
				memset(line, '\0', 512);
			}
		}else
		{
			line[j] = tmp[i];
			j++;
		}

	}
	free(tmp);

	tmp = utils_syscall(utils_strcat("reg query ", REG_PATH_HKLM32));
	memset(line, '\0', 512);
	for (i = 0; i < strlen(tmp); i++)
	{
		if (tmp[i] == '\n'){
			j = 0;
			if (line[0] != '\0')
			{
				utils_add_data(utils_syscall(utils_strcat("reg query \"", utils_strcat(line, "\""))));
				memset(line, '\0', 512);
			}
		}else
		{
			line[j] = tmp[i];
			j++;
		}

	}
	free(tmp);
	return 0;
}

int get_installed_app_via_hkcu()
{
	char *tmp;
	char line[512];
	int i, j = 0;

	tmp = utils_syscall(utils_strcat("reg query ", REG_PATH_HKCU));
	memset(line, '\0', 512);
	for (i = 0; i < strlen(tmp); i++)
	{
		if (tmp[i] == '\n'){
			j = 0;
			if (line[0] != '\0')
			{
				utils_add_data(utils_syscall(utils_strcat("reg query \"", utils_strcat(line, "\""))));
				memset(line, '\0', 512);
			}
		}else
		{
			line[j] = tmp[i];
			j++;
		}

	}
	free(tmp);

	tmp = utils_syscall(utils_strcat("reg query ", REG_PATH_HKCU32));
	memset(line, '\0', 512);
	for (i = 0; i < strlen(tmp); i++)
	{
		if (tmp[i] == '\n'){
			j = 0;
			if (line[0] != '\0')
			{
				utils_add_data(utils_syscall(utils_strcat("reg query \"", utils_strcat(line, "\""))));;
				memset(line, '\0', 512);
			}
		}else
		{
			line[j] = tmp[i];
			j++;
		}

	}
	free(tmp);
	return 0;
}