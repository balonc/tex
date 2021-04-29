#include <stdio.h>

char *binaryls = "/bin/ls";

int main()
{
		char *binaryPath = "/bin/ls";
		char *arg1 = "-lh";
		char *arg2 = "/home";
		char *arg3 = "/etc";
		
		execl(binaryPath, binaryPath, arg1, arg2, arg3, NULL);
		
        return 0;
}