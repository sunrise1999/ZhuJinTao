#include "my.h"
int main()
{
	int pid,s;
	FILE* fp;
	pid_t child1,child2;
	if((fp = fopen("testFile","a")) == NULL)
	{
		perror("fail to open");
		exit(0);
	}
	//wait(0);
	printf("before fork!%d\n",getpid());
	child1 = fork();

	if(child1 == 0)
	{
		if((fp = fopen("testFile","a")) == NULL)
		{
			perror("fail to open");
			exit(0);
		}
		for(int i = 0; i < 10; i++)
		{
			fprintf(fp,"%d",i);
			printf("%d",i);
		}
		fprintf(fp,"\n");
		fclose(fp);
		exit(0);
	}	
	else 
	{
		child2 = fork();
		if(child2 == 0)
		{
			if((fp = fopen("testFile","a")) == NULL)
			{
				perror("fail to open");
				exit(0);
			}

			for(int i = 0; i < 10; i++)
			{
				fprintf(fp,"%d",i);
			}
			fclose(fp);
			exit(0);
		}
		else 
		{
			printf("after fork!%d\n",getpid());
			if((fp = fopen("testFile","rt")) == NULL)
			{
				perror("fail to open file!");
				exit(0);
			}
			while (!feof(fp))
			{
				//printf("putchar!");
				putchar(fgetc(fp));
			}
			fclose(fp);
			exit(0);	
		}
	}
	exit(0);	
}
