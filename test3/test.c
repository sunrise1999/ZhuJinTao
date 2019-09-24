#include "head.h"
int main(void)
{
	int *a = NULL;
	int n = 0;
	printf("请输入数组长度："); 
	scanf("%d",&n);
	a = (int *)malloc(sizeof(int) * n);
	int sum = 0;
	sum  = usum(a,n);
//	BubbleSort(a,n);
//	printf("排序后数组：");
//	for(int i = 0; i < n; i++)
//	{
//		printf("a[%d] = %d\n",i,a[i]);
//	} 
//	getMyTime(a,n);
//	printf("\n总和为：%d\n",sum);
    operator(a,n);

    int i;
    printf("---------------------------------------1:Before Callinng--------------------------------------\n");
    sleep(2);
    printf("---------------------------------------2:After Calling----------------------------------------\n");
    i=system("ls -l");
    printf("---------------------------------------3:After Calling----------------------------------------\n");
	return 0; 
}
