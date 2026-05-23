#include<stdio.h>
#include<stdlib.h>  // 用于 abs 函数

int main()
{
    int n;
    int num = 0;
    int a, b, c;
    scanf("%d", &n);
    int lst[n][3];
    
    // 读取数据
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        lst[i][0] = a;
        lst[i][1] = b;
        lst[i][2] = c;
    }
    
    // 比较每对学生
    for (int k = 0; k < n; k++) {
        for (int l = k + 1; l < n; l++) {  // 从 k+1 开始避免重复计数
            // 检查各科成绩分差
            int diff_chinese = abs(lst[k][0] - lst[l][0]);
            int diff_math = abs(lst[k][1] - lst[l][1]);
            int diff_english = abs(lst[k][2] - lst[l][2]);
            
            // 计算总分
            int total_k = lst[k][0] + lst[k][1] + lst[k][2];
            int total_l = lst[l][0] + lst[l][1] + lst[l][2];
            int diff_total = abs(total_k - total_l);
            
            // 判断是否为旗鼓相当的对手
            if (diff_chinese <= 5 && 
                diff_math <= 5 && 
                diff_english <= 5 && 
                diff_total <= 10) {
                num++;
            }
        }
    }
    
    printf("%d", num);
    return 0;
}