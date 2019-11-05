#include "my.h"
int main()
{
	char *arg[]={"./test","123","abc","hello","ncu","edu",NULL};
	int ret;
	printf("call:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=execvp("test",arg);
	printf("after calling! ret=%d",ret);
	return 1; 
}
