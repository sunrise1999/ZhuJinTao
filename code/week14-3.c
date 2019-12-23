#include "my.h"
#define NUM 4

void * fun(void *arg)
{
    int *pt;
    pt = (int*)arg;
    printf("%d thread:tid %p\n\n",pt,pthread_self());
    printf("pid = %d:worker thread is running!\n",getpid());
    int count = ((int)arg + 1) * 100;
    int sum = 0;
    for(int i = 0;i <= count; i++)
    {
    	sum += i;
    }
    printf("\nsum = %d.\n",sum);
    return NULL;
}

int main()
{
    pthread_t tid[NUM];
    int i,ret[NUM];
    for (int i = 0; i < NUM; i++)
    {
        ret[i] = pthread_create(&tid[i],NULL,fun,(void *)i);
        if (ret[i] != 0)
        {
            printf("thread create failed!\n");
            return -1;
        }

    }
    pthread_join(tid[i],NULL);
    return 0;
}
