//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <sys/timeb.h>
//#include <stdbool.h>
//#include <unistd.h>
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

//排序
/*****************************************************************************************/
//冒泡排序
/***************************************************************/
void BubbleSort(int a[], int n) 
{
	for (int limit = n - 1; limit > 0; limit--) {
		bool flag = false;
		for (int j = 0; j < limit; j++) {
			if (a[j + 1] < a[j]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = true;
			}
		}
		if (!flag) break;
	}
}
/***************************************************************/

//快速排序
/***************************************************************/
//快速排序-交换函数
void swap(int *a, int *b) 
{
   	int tmp = *a;
   	*a = *b;
   	*b = tmp;
}
     
//快速排序-比较函数
int Partition(int a[], int low, int high) 
{
  	int privotkey = a[low];
  	while (low < high) 
	{
   		while (low<high && a[high]>privotkey) --high;
   		swap(&a[low], &a[high]);
   		while (low < high && a[low] < privotkey) ++low;
   		swap(&a[low], &a[high]);
  	}
   	return low;
}

//快速排序-主函数
void QuickSort(int a[], int low, int high) 
{
  	if (low < high) 
	{
  		int privot = Partition(a, low, high);
   		QuickSort(a, low, privot - 1);
   		QuickSort(a, privot + 1, high);
   	}
}
/***************************************************************/
/*****************************************************************************************/

//计算时间
/*****************************************************************************************/
int  getMyTime(int *a,int n)
{
	struct timeb ts1,ts2;
    time_t t1,t2;
    long int ti;
    ftime(&ts1);//执行前时间
//	double diff = 0;
//	time_t theTime1,theTime2;
//	theTime1 = time(NULL);
//	printf("时间为%d\n",(int)(theTime1));
//	struct timeval tv1,tv2;
//	struct timezone tz;
//	gettimeofday(&tv1,&tz);
//	printf("tv-sec:%d\n",tv1.tv_sec);
//	printf("tv-usec:%d\n",tv1.tv_usec);
//	printf("tv-minuteswest:%d\n",tz.tz_minuteswest);
//	printf("tv-dsttime:%d\n",tz.tz_dsttime);
	BubbleSort(a,n);
//	theTime2 = time(NULL);
//	printf("时间为%d\n",(int)(theTime2));
//	printf("时间为%lf\n",difftime(theTime2,theTime1));
//	gettimeofday(&tv2,&tz);
//	printf("tv2-sec:%d\n",tv2.tv_sec);
//	printf("tv2-usec:%d\n",tv2.tv_usec);
//	printf("tv2-usec - tv1-usec:%d\n",tv2.tv_usec-tv1.tv_usec);
	ftime(&ts2);//执行后时间
    t1=(time_t)ts1.time*1000+ts1.millitm;
    printf("t1=%ld\n",t1);
    t2=(time_t)ts2.time*1000+ts2.millitm;
    printf("t2=%ld\n",t2);
    ti=t2-t1;//计算时间差
    printf("时间差%ldms\n",ti);
	return ti;
}

struct thisArg operator(int *a,int n)
{
    struct thisArg m;
    m.ave = 0.0;
    m.sum = 0;
    for(int i = 0;i < n;i++)
    {
        m.sum += a[i];
    }
    m.ave = m.sum /n;
    getMyTime(a,n);
    m.min = a[0];
    m.max = a[n - 1];
    printf("总和为：%ld\n",m.sum);
    printf("平均为：%lf\n",m.ave);
    printf("最大值为：%d\n",m.max);
    printf("最小值为：%d\n",m.min);
}

