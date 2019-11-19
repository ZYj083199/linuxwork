#include "my.h"

void main(){
    int res;
	FILE* fp;
    char buf1[] = "child:123456789";
	char buf2[] = "parent:123456789";
    if((fp = fopen("out.dat","w+"))==NULL){
        printf("error: open file:fork.dat failed.\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if(pid==0){
     	if(fputs(buf1,fp)==EOF)
		{
			perror("dailed to fputs\n");
			return ;
		}
        fclose(fp); 
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
     	exit(EXIT_SUCCESS);
	}
}
