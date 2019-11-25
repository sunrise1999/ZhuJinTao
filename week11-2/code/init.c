/*init.c 程序：生成守护进程*/
#include "my.h"
void init_daemon(void)
{
	pid_t child1,child2;
	int i;
	child1 = fork();
	if(child1>0)
	{
		exit(0);
	}
	else if(child1 < 0)
	{
		perror("创建子进程失败");
		exit(1);
	}
	setsid();
	chdir("/media/zjt/hardStore2/学习用/week11/week11-2/code");
	umask(0);
	for(i = 0;i < NOFILE; ++i)
	{
		close(i);
	}
	return;
}
