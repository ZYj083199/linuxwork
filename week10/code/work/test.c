#include "my.h"
int g=10;
int main()
{
	char buf[]={"0123456789"};
	int s=20;
	static int k=30;
	pid_t pid;
	pid=fork();
	FILE* fp;
	if((fp=fopen("test.dat","w+"))==NULL)
	{
		perror("dailed to fopen \n");
		return -1;
	}
	if(pid<0)
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(pid==0)
	{
		if(fputs(buf,fp)==EOF)
		{
			perror("child:dailed to fputs\n");
		}
		//_exit();
		return 0;
	}
	else{
		if(fputs(buf,fp)==EOF)
		{
			perror("parent:dailed to fputs\n");
		}
		return 0;
	}

}
