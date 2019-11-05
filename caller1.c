#include "my.h"
int main()
{
	int ret;
	printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
	ret = system("/media/zjt/hardStore2/学习用/week9/test9_1");
	sleep(10);
	return 0;
}

