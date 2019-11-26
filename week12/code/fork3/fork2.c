#include "my.h"
int count=0;
int main()
{
	pid_t p1,p2,p3;
	int pipe_fd[2];
	char buf_r[6000];
	int i=0;
	int s1,s2,s3,r1,r2,r3;
	memset(buf_r,0,sizeof(buf_r));
	if(pipe(pipe_fd)<0)
	{
		printf("创建管道失败");
		return -1;
	} 
	p1=fork();
	if(p1<0)
	{
		perror("fork1 failed");
		return -1;
	}
	else if(p1==0)
	{
		count+=1;
		printf("1child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		close(pipe_fd[0]);
		for(i=0;i<=5004;i+=8)
			if(write(pipe_fd[1],"12345678",8)!=-1)
				printf("进程向管道写入%d字节\n",i);
		close(pipe_fd[1]);
		//wait(p2);
		//wait(p3);
		exit(99);
	}
	else
	{
		printf("parent fork second time.\n");
		p2=fork();
		if(p2<0)
		{
			perror("fork2 failed.\n");
			return -1;
		}
		else if(p2==0)
		{
			count+=1;
			printf("2child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
			//while(wait(getppid()));
			sleep(100);
			wait(p1);
			close(pipe_fd[1]);
			if((read(pipe_fd[0],buf_r,6000))>0)
				printf("子进程从管道读取字符=\n%s\n",buf_r);
			close(pipe_fd[0]);
			//wait(p3);
			exit(34);
		}
		else
		{
			printf("parent fork third time.\n");
			p3=fork();
			if(p3<0)
			{
				perror("fork3 failed.\n");
				return -1;
			}
			else if(p3==0)
			{
				count+=1;
				//sleep(200);
				wait(p2);
				printf("3child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
				exit(77);
			}
			else
			{
				printf("parent waiting\n");
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
				printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s3),r1,WEXITSTATUS(s3));
				printf("parent pid=%d,count=%d\n",getpid(),count);
				return 0;
			}
		}
	}
}
