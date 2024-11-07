#include <stdio.h>
#include <stdlib.h>

int main() {
    // 分配内存
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 使用内存
    *ptr = 42;
    printf("Value before free: %d\n", *ptr);

    // 释放内存
    free(ptr);

    // 尝试再次使用已释放的内存（这是错误的！）
    // 此时ptr是一个悬挂指针
    printf("Trying to access freed memory: %d\n", *ptr); // 这可能会导致段错误或其他未定义行为

    // 设置ptr为NULL，以防止悬挂指针的误用（良好实践）
    ptr = NULL;

    // 下面这行代码不会执行，因为前面的printf可能已经触发了错误
    // 为了完整性，仍然展示
    // if (ptr != NULL) {
    //     printf("This should not happen!\n");
    // }

    return 0;
}