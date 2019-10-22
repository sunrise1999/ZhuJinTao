#include "head.h"
int urand(int n)
{
	int temp = 0;
	srand((unsigned)time(0));

	temp = 1 + (rand()/100*(n+1)) %100;
//	printf("生成的随机数为：%d\n",temp);
	return temp;
}
int usum(int *a,int n)
{
	for(int i = 0; i < n ; i++)
	{
		a[i] = urand(i);
//		printf("a[%d] = %d\n",i,a[i]);
	}
	int sum = 0;
	for(int j = 0; j < n; j++)
	{
		sum +=a[j];
	}
	
	return sum;
}


