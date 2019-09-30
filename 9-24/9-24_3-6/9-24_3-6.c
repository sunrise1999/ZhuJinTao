 #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>

int main(int argc, char* argv[]){

//经测试发现可以使用lseek定位至文件任一位置，并用read读任一位置的内容，
//但是write函数会自动将文件偏移量设置在文件结尾，所以写文件时只能从文件尾开始，不能在任一位置。
//
    int fd;
    if(argc !=2){
        printf("input error\n");
        return -1;
    }
    if((fd=open(argv[1], O_RDWR | O_APPEND))<0){
        printf("open error\n");
        return -1;
    }
    if(lseek(fd, 10, SEEK_SET)<0){
        printf("lseek error\n");
        return -1;
    }
    char buf[100];
    if(read(fd,buf, 20)<0){
        printf("read error\n");
        return -1;
    }
    printf("%s\n", buf); 
    if(write(fd, buf, 20)!=20){
    printf("write error\n");
    return -1;
    }
    int new_offset = lseek(fd, 0, SEEK_CUR);
    printf("new offset : %d\n", new_offset);
    return 0;
}

