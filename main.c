#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define filelen 10

int main() {
    int ret,i = 0;
    FILE * fp = fopen("test5file.txt","w+");
    FILE * fcopy = fopen("test5fileCopy.txt","w+");
    if(fp < 0)
    {
        exit(1);
    }
    char buf_w[filelen] = {"HeLlow!___"};
    for(i=0;i<filelen;i++)
    {
        printf("[%d] %c ",i,buf_w[i]);
    }
    printf("\n");
    char buf_r[filelen];
    //打印    [0] H [1] e [2] L [3] l [4] o [5] w [6] ! [7] _ [8] _ [9] _
    ret = fwrite(buf_w,sizeof(char),filelen,fp);  //此时文件指针已经到了文件尾部
    printf("fwrite: %d\n",ret);
    printf("\n");

    rewind(fp);       //将文件指针置于文件头部


    memset(buf_r,0,sizeof(buf_r));
    ret = fread(buf_r,sizeof(char),filelen,fp);  //此时文件指针再次到了尾部
    printf("fread: %d\n",ret);
    printf("\n");

    for(i=0;i<filelen;i++)
    {
        printf("[%d] %c ",i,buf_r[i]);
        printf("\n");
    }
    //打印    [0] H [1] e [2] L [3] l [4] o [5] w [6] ! [7] _ [8] _ [9] _
    ret = fseek(fp,0,SEEK_SET);          //将文件指针置于距离 头部 偏移量 为 0 的位置，等同于rewind()
    memset(buf_r,0,sizeof(buf_r));
    ret = fread(buf_r,sizeof(char),filelen,fp);   //文件指针到达文件尾部
    printf("fread: %d\n",ret);
    printf("\n");
    if (ret > 0)
    {
        for(i=0;i<filelen;i++)
        {
            printf("[%d] %c ",i,buf_r[i]);
        }
        printf("\n");
    }
    printf("1 ret:%d  buf_r[0]:%c\n",ret,buf_r[0]);
    printf("\n");

    printf("复制开始！");
    fwrite(buf_r,sizeof(char),filelen,fcopy);
    printf("复制完成！");

    fclose(fp);
    fclose(fcopy);
    return 0;
}