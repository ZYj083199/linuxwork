#include "my.h"
int i=0;
int fun(void *d)
{
	i++;
	printf("tid=%p\n",pthread_self());
}
int main()
{
	pthread_t tid;
	int ret[4],i;
	for(i=0;i<4;i++)
	{
		ret[i]=pthread_create(&tid,NULL,(void *(*)())fun,NULL);
		if(ret[i]!=0)
		{
			perror("failed!\n");
			return -i;
		}
	}
	
	for(i=0;i<4;i++)
		pthread_detach(tid);
	sleep(10);
	printf("Master Done\n");
	return 0;
}
