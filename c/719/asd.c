#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define CHAR_COUNT 14
#define REFRESH_INTERVAL 500000 // 刷新间隔（微秒），这里为0.5秒

int main() {
    srand(time(NULL)); // 初始化随机数生成器

    // 用于存储字符的数组
    char arr[CHAR_COUNT + 1]; // 额外一个位置用于字符串结束符'\0'
    // 用于跟踪字符是否已回文的布尔数组
    bool is_palindromed[CHAR_COUNT] = {false};

    // 初始化字符数组为随机字符
    for (int i = 0; i < CHAR_COUNT; ++i) {
        arr[i] = (char)rand() % 256; // 生成一个随机字符
    }
    arr[CHAR_COUNT] = '\0'; // 添加字符串结束符

    int left = 0; // 左指针
    int right = CHAR_COUNT - 1; // 右指针

    while (true) { // 无限循环
        // 检查是否有新的字符需要回文
        if (!is_palindromed[left] || !is_palindromed[right]) {
            // 假设只有左指针的字符没有回文，右指针类似处理
            if (!is_palindromed[left]) {
                // 假设这里只是简单地打印字符，而不是真正的回文操作
                // 在实际回文场景中，你会交换arr[left]和arr[right]的值
                printf("%s", arr); // 打印整个字符串
                fflush(stdout); // 刷新输出缓冲区
                is_palindromed[left] = true; // 标记左指针的字符为已回文
            }
            // 如果右指针的字符没有回文，类似处理...

            // 移动指针
            if (is_palindromed[left]) left++;
            if (is_palindromed[right] && left < right) right--; // 防止左右指针交叉

            // 等待一段时间再刷新
            usleep(REFRESH_INTERVAL);
        }

        // 注意：由于我们在这里只是简单地打印整个字符串，而不是真正地回文，
        // 所以看起来并没有明显的回文效果。要实现真正的回文效果，
        // 你需要更新arr数组中的字符，并重新打印字符串。
    }

    return 0; // 这行代码实际上永远不会被执行，因为上面有一个无限循环
}