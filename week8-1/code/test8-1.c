#include<stdio.h>    
#include <malloc.h>    
void print(char *,int);    

int main()    
{    

    char *s1 = "abcde";  //"abcde"��Ϊ�ַ��������洢�ڳ����� s1��s2��s5ӵ����ͬ�ĵ�ַ  

    char *s2 = "abcde";    

    char s3[] = "abcd";    

    long int *s4[100];    

    char *s5 = "abcde";    

    int a = 5;    

    int b =6;//a,b��ջ�ϣ�&a>&b��ַ��������    

     

    printf("variables address in main function: s1=%p  s2=%p s3=%p s4=%p s5=%p a=%p b=%p \n",     

            s1,s2,s3,s4,s5,&a,&b);   

    printf("variables address in processcall:n");    

       print("ddddddddd",5);//������ջ�����������,p�Ƚ�ջ,str��� &p>&str    

    printf("main=%p print=%p \n",main,print);    

     //��ӡ����������������Ӻ����ĵ�ַ������ʱ�ȱ���ĵ�ַ�ͣ������ĵ�ַ��main<print    

 }    

  

 void print(char *str,int p)  
{    

    char *s1 = "abcde";  //abcde�ڳ�������s1��ջ��    

    char *s2 = "abcde";  //abcde�ڳ�������s2��ջ�� s2-s1=6���ܵ���0���������Ż�����ͬ�ĳ�����ֻ���ڴ汣��һ��    

    //��&s1>&s2    

    char s3[] = "abcdeee";//abcdeee�ڳ�������s3��ջ�ϣ����鱣�������Ϊabcdeee��һ�ݿ���    

    long int *s4[100];    

    char *s5 = "abcde";    

    int a = 5;    

    int b =6;    

    int c;    

    int d;           //a,b,c,d����ջ�ϣ�&a>&b>&c>&d��ַ��������    

    char *q=str;   

    int m=p;           

    char *r=(char *)malloc(1);    

    char *w=(char *)malloc(1) ;  // r<w ����������    

    

    printf("s1=%p s2=%p s3=%p s4=%p s5=%p a=%p b=%p c=%p d=%p str=%p q=%p p=%p m=%p r=%p w=%p \n",    

            s1,s2,s3,s4,s5,&a,&b,&c,&d,&str,q,&p,&m,r,w);   

    /* ջ�Ͷ����ڳ�������ʱ��̬����ģ��ֲ���������ջ�Ϸ��䡣 

        ջ�Ƿ��������ģ���ַ�ݼ���malloc�ȷ�����ڴ�ռ��ڶѿռ䡣�������������ģ���ַ������   

        r,w������ջ��(��&r>&w)��r,w��ָ�����ڶ���(��r<w)��*/   

 }    
