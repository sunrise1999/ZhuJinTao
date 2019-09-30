#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    int fdSur,fdTo;
    int size,n = 0;
    if(argc !=3){
        printf("input error\n");
        return -1;
    }
    if((fdSur=open(argv[1], O_RDWR | O_APPEND))<0){
        printf("open error\n");
        return -1;
    }
    if((fdTo=open(argv[2], O_RDWR | O_APPEND))<0){
        printf("open error\n");
        return -1;
    }
    if(lseek(fdSur, 10, SEEK_SET)<0){
        printf("lseek error\n");
        return -1;
    }
    char buf[10240];
    if(lseek(fdTo, 0, SEEK_SET)<0){
        printf("lseek error\n");
        return -1;
    }
    n = read(fdSur,buf, 10240);
    if(n<0){
        printf("read error\n");
        return -1;
    }
    size = n;
    printf("读取字节数为：%d\n",n);
//    printf("%s\n", buf);

    n = write(fdTo, buf, size);
    if(n >= 10240 | n < 0){
        printf("write error\n");
//        return -1;
    }
    
    printf("写入字节数为：%d\n",n);
    char bufEnd[20] = { '1' };

    n = write(fdTo, bufEnd, 20);
    if(n!=20){
        printf("write error\n");
//        return -1;
    }
    printf("写入字节数为：%d\n",n);

    int new_offset = lseek(fdTo, 0, SEEK_CUR);
    printf("new offset : %d\n", new_offset);
    return 0;
}
