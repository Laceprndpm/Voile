#include <stdio.h>

int main()
{
    char buf[BUFSIZ]; // BUFSIZ 是一个在 stdio.h 中定义的常量，表示标准缓冲区的默认大小

    // 查询当前缓冲模式
    int current_mode = setvbuf(stdout, NULL, _IONBF, 0); // _IONBF 代表无缓冲模式

    if (current_mode != 0)
    {
        printf("Failed to get current buffering mode.\n");
    }
    else
    {
        printf("stdout is currently using no buffering.\n");
    }
}