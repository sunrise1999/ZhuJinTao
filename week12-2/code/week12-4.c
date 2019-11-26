#include "my.h"

void sighandler(int signo);
int main()
{
	int fd[2];
    if (signal(SIGPIPE,sighandler) == SIG_ERR)
    {
        fprintf(stderr,"signal error (%s)\n",strerror(errno));
        exit(-1);
    }
    if (pipe(fd) == -1)
    {
        fprintf(stderr,"pipe create failed.\nerror reason = %s\n",strerror(errno));
        return -1;
    }
    pid_t pid;
    pid = fork();
    pid = fork();
    if(pid < 0)
    {
        fprintf(stderr,"fork failed.\nerror reason = %s\n",strerror(errno));
        exit(-3);
    }    
    else if(pid == 0)
    {
        fprintf(stdout,"[child] i will close the last read ebd of pipe.pd = %d,ppid = %d\n",getpid(),getppid());
        sleep(300);
        close(fd[0]);
        exit(0);
    }
    else
    {
        close(fd[0]);
        sleep(5);
        int ret;
        ret = write(fd[1],"hello",5);
        if (ret == -1)
        {
            fprintf(stderr, "parent write error (%s)\n",strerror(errno));
        }
        return 0;      
    }    
}

void sighandler(int signo)
{
    printf("[parent] catch a SIGPIPE signal and signum=%d\n",signo);
}
