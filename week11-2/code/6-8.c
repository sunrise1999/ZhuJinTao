/*6-8.c程序：主程序每隔一分钟向/tmp目录中的日志6-8.log报告运行状态*/
#include "my.h"
#include <time.h>
void init_daemon(void);
int main(void)
{
	FILE *fp;
	time_t t;
	init_daemon();
	while(1)
	{
		sleep(10);
		if((fp = fopen("6-8.log","a")) >= 0)
		{
			t = time(0);
			fprintf(fp,"守护进程还在运行，时间是：%s",asctime(localtime(&t)));
			fclose(fp);
		}
	}
	return 0;
}
