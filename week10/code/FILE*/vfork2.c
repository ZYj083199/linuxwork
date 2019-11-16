#include "my.h"

void main(){
    printf("parent running.\n");
    int res;
	FILE* fp;
    char buf1[] = "child:123456789";
	char buf2[] = "parent:123456789";
    if((fp = fopen("vfork2.dat","w+"))==NULL){
        printf("error: open file:vfork.dat failed.\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid = vfork();
    if(pid==0){
            // 子进程
    	printf("child process running.\n");
     	if(fputs(buf1,fp)==EOF)
		{
			perror("dailed to fputs\n");
			return ;
		}
        //fclose(fp); 
        printf("child process done.\n");
        exit(0);
	}
    else if(pid==-1){
            // error
   		exit(EXIT_FAILURE);
	}
    else{
    	if(fputs(buf2,fp)==EOF)
		{
			perror("dailed to fputs\n");
			return ;
		}
    	fclose(fp);
		printf("parent process done.\n");
     	exit(EXIT_SUCCESS);
	}
}
