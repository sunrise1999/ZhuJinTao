#include "my.h"
int count = 0;
int main()
{
	pid_t p1,p2,p3;
	p1 = fork();
	int s1,s2,s3,r1,r2,r3;

	if(p1 < 0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(p1 == 0)
	{
		count += 1;
		printf("ppid = %d pid=%d,count=%d.\n",getppid(),getpid(),count);
		exit(99);
	}else
	{
		printf("parent fork second time.\n");
		p2 = fork();
		if(p2 < 0)
		{
			perror("fork failed.\n");
			return -1;
		} else if(p2 == 0)
		{
			count += 1;
			printf("ppid = %d pid=%d,count=%d.\n",getppid(),getpid(),count);
			exit(34);
		} 
		else 
		{
			printf("parent fork third time.\n");
			p3 = fork();
			 if(p3 < 0)
			{
				perror("fork failed.\n");
				return -1;
			} else if(p3 == 0)
			{
				printf("ppid = %d pid=%d,count=%d.\n",getppid(),getpid(),count);
				exit(77);
			}else 
			{
				printf("parent is waiting.\n");
				r1 = wait(&s1);
				r2 = wait(&s2);
				r3 = wait(&s3);
				printf("r1:%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
				return 0;
			}	
		}
	}	 
	
}
