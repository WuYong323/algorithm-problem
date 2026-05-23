#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char digits[1000];
    
    // 读取输入
    scanf("%d", &n);
    scanf("%s", digits);
    
    // 定义每个数字的5行显示模式
    const char *numbers[10][5] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"}, // 0
        {"..X", "..X", "..X", "..X", "..X"}, // 1
        {"XXX", "..X", "XXX", "X..", "XXX"}, // 2
        {"XXX", "..X", "XXX", "..X", "XXX"}, // 3
        {"X.X", "X.X", "XXX", "..X", "..X"}, // 4
        {"XXX", "X..", "XXX", "..X", "XXX"}, // 5
        {"XXX", "X..", "XXX", "X.X", "XXX"}, // 6
        {"XXX", "..X", "..X", "..X", "..X"}, // 7
        {"XXX", "X.X", "XXX", "X.X", "XXX"}, // 8
        {"XXX", "X.X", "XXX", "..X", "XXX"}  // 9
    };
    
    // 输出5行
    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < n; i++) {
            int digit = digits[i] - '0'; // 将字符转换为数字
            
            // 输出该数字在当前行的模式
            printf("%s", numbers[digit][row]);
            
            // 如果不是最后一个数字，添加间隔
            if (i < n - 1) {
                printf(".");
            }
        }
        printf("\n");
    }
    
    return 0;
}