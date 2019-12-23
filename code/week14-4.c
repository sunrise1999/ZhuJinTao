/*
#include "my.h"
void *fun(void *arg)
{
    //int i = 9;
    int *i = (int *)malloc(sizeof(int));
    printf("tid = %p\n",(unsigned int)pthread_self());
    *i = 99;
    printf("i=%d,&i=%p\n",i,*i);
    pthread_exit((void*)i);
}

int main()
{
    pthread_t tid;
    int ret,**rv;
    ret = pthread_create(&tid,NULL,fun,NULL);
    if(ret != 0)
    {
        perror("failed!\n");
        return -1;
    }
    pthread_join(tid,(void **)&rv);
    printf("rv=%d,%p\n",*rv,*rv);
    return 0;
}
*/
#include "my.h"
#define NUM 4
int sum = 0;

void * fun(void *arg)
{
	//int *sum = (int *)malloc(sizeof(int));
    int *pt;
    pt = (int*)arg;
    printf("%d thread:tid %p\n\n",pt,pthread_self());
    printf("pid = %d:worker thread is running!\n",getpid());
    int count = ((int)arg + 1) * 100;
    sum = 0;
    for(int i = 0;i <= count; i++)
    {
    	sum += i;
    }
    //printf("\nsum = %d.\n",sum);
    pthread_exit((void *)&sum);
}

int main()
{
    pthread_t tid[NUM];
    int i,ret[NUM];
    int **rv;
    for (int i = 0; i < NUM; i++)
    {
        ret[i] = pthread_create(&tid[i],NULL,fun,(void *)i);
        if (ret[i] != 0)
        {
            printf("thread create failed!\n");
            return -1;
        }
		pthread_join(tid[i],(void **)&rv);
    	printf("master printf:sum=%d\n",*rv);
    }
    
    return 0;
}
