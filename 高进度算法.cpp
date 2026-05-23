#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 100  // 最大位数，50!大约65位，100位足够

// 高精度数结构
typedef struct {
    int digits[MAX_DIGITS];  // 存储各位数字，digits[0]是个位
    int len;                 // 数字长度
} BigInt;

// 初始化大整数为0
void init(BigInt *a) {
    memset(a->digits, 0, sizeof(a->digits));
    a->len = 1;
}

// 从整数初始化大整数
void from_int(BigInt *a, int num) {
    init(a);
    
    if (num == 0) {
        a->len = 1;
        a->digits[0] = 0;
        return;
    }
    
    a->len = 0;
    while (num > 0) {
        a->digits[a->len++] = num % 10;
        num /= 10;
    }
}

// 高精度加法：a = a + b
void add(BigInt *a, const BigInt *b) {
    int carry = 0;
    int max_len = (a->len > b->len) ? a->len : b->len;
    
    for (int i = 0; i < max_len || carry; i++) {
        if (i >= a->len) {
            a->digits[a->len] = 0;
            a->len++;
        }
        
        int sum = a->digits[i] + (i < b->len ? b->digits[i] : 0) + carry;
        a->digits[i] = sum % 10;
        carry = sum / 10;
    }
}

// 高精度乘法：a = a * b（b是普通整数）
void multiply_int(BigInt *a, int b) {
    int carry = 0;
    
    for (int i = 0; i < a->len || carry; i++) {
        if (i >= a->len) {
            a->digits[a->len] = 0;
            a->len++;
        }
        
        int product = a->digits[i] * b + carry;
        a->digits[i] = product % 10;
        carry = product / 10;
    }
    
    // 去除前导零
    while (a->len > 1 && a->digits[a->len - 1] == 0) {
        a->len--;
    }
}

// 输出大整数
void print(const BigInt *a) {
    for (int i = a->len - 1; i >= 0; i--) {
        printf("%d", a->digits[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    BigInt sum, factorial;
    init(&sum);         // 初始化总和为0
    from_int(&factorial, 1);  // 初始化阶乘为1
    
    for (int i = 1; i <= n; i++) {
        multiply_int(&factorial, i);  // 计算i!
        add(&sum, &factorial);        // 将i!加到总和中
    }
    
    print(&sum);  // 输出结果
    
    return 0;
}