#include <stdio.h>
#include <sys/utsname.h>

int main() {

	struct utsname system_info;

	uname(&system_info);

	printf("Sysname: %s\n", system_info.sysname);
	printf("Nodename: %s\n", system_info.nodename);
	printf("Release: %s\n", system_info.release);
	printf("Version: %s\n", system_info.version);
	printf("Machine: %s\n", system_info.machine);
  
}
