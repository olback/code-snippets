int main() {

	struct utsname system;

	uname(&system);

	printf("Sysname: %s\n", system.sysname);
	printf("Nodename: %s\n", system.nodename);
	printf("Release: %s\n", system.release);
	printf("Version: %s\n", system.version);
	printf("Machine: %s\n", system.machine);
  
}
