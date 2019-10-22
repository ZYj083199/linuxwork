#include "dylib.h"
#include <stdio.h>
int main()
{
	int a[20];
	init(a,20);
	show(a,20);
	printf("sum=%d\n",sum(a,20));
	printf("max=%d\n",max(a,20));
	return 0;
}
