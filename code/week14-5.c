#include "my.h"
#define NUM 4
struct sendval{
    int n;
    int s;
};

void * fun(void *arg)
{
    struct sendval * k = (struct sendval *)arg;
    int i = 0,sum = 0;
    for (int i = 0; i <= k->s; i++)
    {
        sum += i;
    }

    printf("\nworker---%d:pthread_self return %p,sum of %d = %d.\n",k->n,(void*)pthread_self(),k->s,sum);
    pthread_exit(NULL);
    return NULL;
}

int main()
{
    pthread_t tid[NUM];
    int ret[NUM];
    struct sendval d[NUM];
    for (int i = 0; i < NUM; i++)
    {
        d[i].n = i;
        d[i].s = 100*(i+1);
        ret[i] = pthread_create(&tid[i],NULL,fun,(void *)&d[i]);
        if (ret[i] != 0)
        {
            printf("thread create failed!\n");
            return -1;
        }

    	//printf("master printf:sum=%d\n",*rv);
    }
    for (int i = 0; i < NUM; i++)
    {
        //pthread_join(tid[i],NULL);
        pthread_detach(tid[i]);
    }
    printf("Master %d : All Done!\n",getpid());
    sleep(30);
        
    return 0;
}
