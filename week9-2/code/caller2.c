#include "my.h"
int main()
{
	int ret;
	printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
	//ret = system("/media/zjt/hardStore2/学习用/week9test/test9_1");
		execl("/media/zjt/hardStore2/学习用/week9/test9_1","./test1","123","456",NULL);
	sleep(100);
	return 0;
}

