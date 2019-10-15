#include "/media/zjt/hardStore2/学习用/week5/week5-1/head.h"
//排序
/*****************************************************************************************/
//冒泡排序
/***************************************************************/
void BubbleSort(int a[], int n) 
{
	for (int limit = n - 1; limit > 0; limit--) {
		bool flag = false;
		for (int j = 0; j < limit; j++) {
			if (a[j] < a[j + 1]) {
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

/*****************************************************************************************/

//计算时间
/*****************************************************************************************/
int  getMyTime(int *a,int n)
{
	struct timeb ts1,ts2;
    time_t t1,t2;
    long int ti;
    ftime(&ts1);//执行前时间

	BubbleSort(a,n);

	ftime(&ts2);//执行后时间
    t1=(time_t)ts1.time*1000+ts1.millitm;
    printf("t1=%ld\n",t1);
    t2=(time_t)ts2.time*1000+ts2.millitm;
    printf("t2=%ld\n",t2);
    ti=t2-t1;//计算时间差
    printf("时间差%ld\n",ti);
	printf("最大值%d\n",a[0]);
	return ti;
}
