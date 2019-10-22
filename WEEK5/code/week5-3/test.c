#include "head.h"
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(void)
{
	void * handle;
	int(*f1)();
	int(*f2)();
	char *error;
	handle = dlopen("/media/zjt/hardStore2/学习用/week5/code/week5-3/libabc.so",RTLD_LAZY);
	if(!handle)
	{
		perror("load failed!\n");
	}	
	f1 = dlsym(handle,"usum");
	if((error = dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}	
	f2 = dlsym(handle,"getMyTime");
	if((error = dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);		
	}
	int *a = NULL;
	int n = 0;
	printf("请输入数组长度："); 
	scanf("%d",&n);
	a = (int *)malloc(sizeof(int) * n);
	int sum = 0;
	sum  = f1(a,n);
	f2(a,n);
	printf("\n总和为：%d\n",sum);
	system("pause");
	return 0; 
}
