#include "myhead.h"
char str[27];
void menu()
{
	FILE* p;
	int x; 
	while(1)
	{
		//system("cls");
		printf("***********************************\n");
		printf("0.退出\n");
		printf("1. 创建新文件\n");
		printf("2. 写文件\n");
		printf("3. 读文件\n");
		printf("4. 修改文件权限\n");
		printf("5. 查看当前文件的权限修改文件权限\n");
		printf("***********************************\n");
		printf("Please input your choice(0-6):");
		scanf("%d",&x);
		switch(x)
		{
			case 0:
				return;
			case 1:
				GetFileName();
				CreatNewFile();
				WriteFile();			
				break;
			case 2:
				GetFileName();
				WriteFile();
				break;
			case 3:
				GetFileName();
				ReadFile();
				break;
			case 4:
				GetFileName();
				ChangePower();
				break;
			case 5:
				GetFileName();
				WatchPower();
				ChangePower();
				break;
			default:
				break;
		}
		//str="";
		p=NULL;
	}
}
void GetFileName()
{
	printf("请输入文件名:");
	scanf("%s",str);
}
void CreatNewFile()
{
	FILE *p=fopen(str,"at");
	fclose(p);
}
void WriteFile()
{
	char st[100];
	FILE* p=fopen(str,"at");
	if(p==NULL)exit(0);
	printf("请输入内容:\n");
	scanf("%s",st);
	//printf("1");
	fputs(st,p);
	fclose(p);
}
void ReadFile()
{
	char st[100];
	FILE* p=fopen(str,"rt");
	fgets(st,100,p);
	printf("%s",st);
	printf("\n");
	fclose(p);
}
void ChangePower()
{
	int p;
	printf("请输入修改权限:(写04,读02,写读06)");
	scanf("%d",&p);
	chmod(str,p);
}
void WatchPower()
{
	int p;
	if(!access(str,04))
		printf("写");
	if(!access(str,02))
		printf("读");
	printf("\n");
}
