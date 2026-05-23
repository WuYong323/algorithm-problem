// 引入输入输出流库，用于cout和cin
#include <iostream>
// 引入数学库，用于pow、sqrt等数学函数
#include <cmath>
// 引入Windows系统库，用于Sleep延时函数
#include <windows.h>
// 使用标准命名空间，避免每次写std::
using namespace std;

// 声明爱心程序函数，无参数，无返回值
void heartProgram() {
    // 定义变量rows，用于存储用户输入的爱心行数
    int rows;
    // 输出爱心程序的标题横线
    cout << "\n========== 爱心程序 ==========" << endl;
    // 提示用户输入爱心的行数，给出推荐范围
    cout << "请输入爱心的行数（10~100行最佳）: ";
    // 接收用户输入的行数值，存储到rows变量中
    cin >> rows;

    // 计算y轴的步长：y轴总范围是3（从1.5到-1.5），除以行数得到每行的高度
    double yStep = 3.0 / rows;      // y轴步长
    // 计算x轴的步长：是y轴的一半，保持2:1的宽高比，让爱心更美观
    double xStep = yStep / 2.0;      // x轴步长（保持2:1宽高比）

    // y轴外层循环：从上到下遍历，从1.5开始，每次减yStep，直到-1.5
    for (double y = 1.5; y >= -1.5; y -= yStep) {
        // x轴内层循环：从左到右遍历，从-1.5开始，每次加xStep，直到1.5
        for (double x = -1.5; x <= 1.5; x += xStep) {
            // 心形方程：(x² + y² - 1)³ - x² * y³ ≤ 0
            // 计算a = x² + y² - 1，这是心形方程的核心部分
            double a = x * x + y * y - 1;
            // 判断点(x, y)是否在心形内部：如果a³ - x²*y³ ≤ 0，则点在心形内
            if (a * a * a - x * x * y * y * y <= 0.0) {
                // 如果在心形内部，打印星号
                cout << "*";
            } else {
                // 如果在心形外部，打印空格
                cout << " ";
            }
        }
        // 一行打印完毕，输出换行符
        cout << endl;
    }
}

// 声明感叹号程序函数，无参数，无返回值
void exclamationProgram() {
    // 输出感叹号程序的标题横线
    cout << "\n========== 感叹号程序 ==========" << endl;
    // 打印感叹号的上半部分（10个星号行），构成竖线
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
    // 打印一行空格，作为感叹号的分隔
    cout << "           " << endl;
    // 打印感叹号的下半部分（3个星号行），构成底部圆点
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
    cout << "    ***    " << endl;
}

// 声明箭头程序函数，无参数，无返回值
void arrowProgram() {
    // 定义终端宽度为50个字符
    int width = 50;  // 终端宽度
    // 定义箭头的形状字符串，包含4个短横线和一个箭头符号
    string arrow = "----->";  // 箭头形状

    // 输出箭头程序的标题横线
    cout << "\n========== 箭头程序 ==========" << endl;
    // 提示用户动画即将开始
    cout << "箭头射星动画开始！" << endl;
    // 提示用户按键继续（需要按两次Enter，因为前面可能还有未处理的输入）
    cout << "按Enter继续..." << endl;
    // 第一次get()清空输入缓冲区
    cin.get();
    // 第二次get()等待用户按下Enter键
    cin.get();

    // 循环让箭头从左向右移动，移动距离为总宽度减去箭头长度
    for (int i = 0; i <= width - arrow.length(); i++) {
        // 输出回车符\r，让光标回到当前行开头，实现动画效果
        cout << "\r";

        // 循环打印i个空格，让箭头向右移动
        for (int j = 0; j < i; j++) {
            // 每次打印一个空格
            cout << " ";
        }

        // 打印箭头形状，箭头始终保持固定长度
        cout << arrow;

        // 循环打印中间的空格，从箭头结束位置到目标前
        for (int j = i + arrow.length(); j < width - 1; j++) {
            // 每次打印一个空格
            cout << " ";
        }

        // 打印右边的星号目标，flush立即输出到屏幕
        cout << "*" << flush;

        // 延时50毫秒，控制箭头移动速度
        Sleep(50);

        // 判断箭头是否已经到达目标位置前
        if (i >= width - arrow.length() - 1) {
            // 输出换行符，命中提示文字
            cout << endl << "命中目标！" << endl;
            // 跳出循环，动画结束
            break;
        }
    }
}

// 主函数，程序入口
int main() {
    // 定义变量choice，用于存储用户在菜单中的选择
    int choice;

    // while(true)无限循环，保持菜单一直运行，直到用户选择退出
    while (true) {
        // 输出菜单上边框
        cout << "\n========================================" << endl;
        // 输出菜单标题
        cout << "           主菜单              " << endl;
        // 输出菜单下边框
        cout << "========================================" << endl;
        // 输出选项1：爱心程序
        cout << "1. 爱心程序" << endl;
        // 输出选项2：感叹号程序
        cout << "2. 感叹号程序" << endl;
        // 输出选项3：箭头程序
        cout << "3. 箭头程序" << endl;
        // 输出选项0：退出程序
        cout << "0. 退出" << endl;
        // 输出菜单底部边框
        cout << "========================================" << endl;
        // 提示用户输入选择
        cout << "请输入你的选择 (0-3): ";
        // 接收用户输入的选项，存储到choice变量中
        cin >> choice;

        // 使用switch语句根据用户的选择执行不同的功能
        switch (choice) {
            // case 1：用户选择了爱心程序
            case 1:
                // 调用heartProgram()函数执行爱心程序
                heartProgram();
                // break跳出switch语句
                break;
            // case 2：用户选择了感叹号程序
            case 2:
                // 调用exclamationProgram()函数执行感叹号程序
                exclamationProgram();
                // break跳出switch语句
                break;
            // case 3：用户选择了箭头程序
            case 3:
                // 调用arrowProgram()函数执行箭头程序
                arrowProgram();
                // break跳出switch语句
                break;
            // case 0：用户选择退出程序
            case 0:
                // 输出告别信息
                cout << "再见！" << endl;
                // return 0正常退出程序
                return 0;
            // default：用户输入了无效的选项
            default:
                // 提示用户选择无效，需要重新输入
                cout << "无效选择，请重新输入！" << endl;
        }

        // 提示用户按键返回主菜单（需要按两次Enter）
        cout << "\n按Enter返回主菜单...";
        // 第一次get()清空输入缓冲区
        cin.get();
        // 第二次get()等待用户按下Enter键
        cin.get();
    }

    // 程序正常结束，返回0
    return 0;
}
