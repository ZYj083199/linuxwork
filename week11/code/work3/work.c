#include "my.h"
int main()
{
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[6000];
	int i=0;
	memset(buf_r,0,sizeof(buf_r));
	if(pipe(pipe_fd)<0)
	{
		printf("创建管道失败");
		return -1;
	} 
	result=fork();
	while(1){
		if(result<0)
		{
			perror("创建子进程失败");
			exit(0);
		}
		else if(result==0)
		{	
			close(pipe_fd[1]);
			if((r_num=read(pipe_fd[0],buf_r,6000))>0)
				printf("子进程从管道读取%d个字符\n",r_num);
			close(pipe_fd[0]);
			exit(0);
		}
		else
		{	
			close(pipe_fd[0]);
			for(i=0;i<5000;i+=8)
				if(write(pipe_fd[1],"12345678",8)==-1)
					printf("父进程向管道写入%d字节\n",i);
			close(pipe_fd[1]);
			waitpid(result,NULL,0);
			exit(0);
		}
	}
}
