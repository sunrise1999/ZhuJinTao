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
	getMyTime(a,n);
	printf("\n总和为：%d\n",sum);
	system("pause");
	return 0; 
}
