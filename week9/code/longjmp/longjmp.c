#include <setjmp.h>
#include "my.h"
static jmp_buf g_stack_env;
static void func2(void)
{
	printf("Enter func2\n");
	longjmp(g_stack_env,1);
	printf("Leave func2\n");
}
static void func1(void)
{
	printf("Enter func1\n");
	func2();
}

int main(void)
{
	if(0==setjmp(g_stack_env)){
		printf("Normal flow\n");
		func1();
	}else{
		printf("Long jmp flow\n");
	}
	return 0;
}



