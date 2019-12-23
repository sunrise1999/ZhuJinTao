#include "my.h"
//gcc week13-7.c -o week13-7 -lpthread 注意！要加上-lpthread这个库才能编译成功
void *threadfun(void *arg)
{
	printf("thread fun.pid = [%5d]\n",getpid());
	return (void *)0;
}

int main()
{
	pthread_t tid;
    int error;
    error = pthread_create(&tid,NULL,threadfun,NULL);
    if (error != 0)
    {
        perror("thread create failed.\n");
        return -1;
    }
    printf("Done!\n");
    return 0;    
}
