#include "my.h"
int main()
{
	int ret;
	printf("call:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=system("./test 123 abc hello ncu edu");
	printf("after calling! ret=%d",ret);
	return 1; 
}
