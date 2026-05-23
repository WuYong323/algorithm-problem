/*
 * 图形菜单程序
 * 功能：显示心形、感叹号、移动箭头动画
 * 作者：小弗 AI 助手
 * 日期：2026-03-09
 */

#include <iostream>
#include <string>
#include <limits>

// 跨平台支持
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

// ============== 工具函数 ==============

/**
 * 清屏函数 - 跨平台实现
 */
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
 * 延迟函数 - 跨平台实现
 * @param milliseconds 延迟的毫秒数
 */
void sleepMs(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

/**
 * 暂停等待用户按 Enter
 */
void pause() {
    cout << "\n按 Enter 键继续...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// ============== 图形显示函数 ==============

/**
 * 显示心形图案
 * 使用 ASCII 字符构建对称的心形
 */
void showHeart() {
    cout << "\n\n";
    cout << "          *****           *****\n";
    cout << "        *******         *******\n";
    cout << "       *********       *********\n";
    cout << "      ***********     ***********\n";
    cout << "     *************   *************\n";
    cout << "    *************** ***************\n";
    cout << "    ***********************************\n";
    cout << "     *********************************\n";
    cout << "      *******************************\n";
    cout << "       *****************************\n";
    cout << "        ***************************\n";
    cout << "          *************************\n";
    cout << "            ***********************\n";
    cout << "              *********************\n";
    cout << "                *******************\n";
    cout << "                  ***************\n";
    cout << "                    ***********\n";
    cout << "                      *********\n";
    cout << "                        *******\n";
    cout << "                          *****\n";
    cout << "                            ***\n";
    cout << "                             *\n";
    cout << "\n";
}

/**
 * 显示感叹号图案
 * 上半部分是竖线，下半部分是一个点
 */
void showExclamation() {
    cout << "\n\n";
    
    // 竖线部分
    for (int i = 0; i < 10; i++) {
        cout << "      ***\n";
    }
    
    cout << "\n";
    
    // 底部点
    cout << "     ***\n";
    cout << "      *\n";
    
    cout << "\n";
}

/**
 * 显示移动的箭头动画
 * 箭头从左到右移动，再从右到左返回
 */
void showMovingArrow() {
    const int MAX_STEPS = 35;
    const int DELAY_MS = 80;
    
    // 从左到右移动
    for (int i = 0; i < MAX_STEPS; i++) {
        clearScreen();

        // 生成前导空格
        string spaces(i, ' ');

        cout << "\n\n\n\n";
        cout << spaces << "     ---->\n";
        cout << spaces << "    ----->\n";
        cout << spaces << "   ------>\n";

        cout << "\n\n";
        cout << "箭头正在从左向右移动... (" << i + 1 << "/" << MAX_STEPS << ")\n";

        sleepMs(DELAY_MS);
    }

    // 短暂停留
    sleepMs(500);

    // 从右到左移动
    for (int i = MAX_STEPS - 1; i >= 0; i--) {
        clearScreen();

        string spaces(i, ' ');

        cout << "\n\n\n\n";
        cout << spaces << "     ---->\n";
        cout << spaces << "    ----->\n";
        cout << spaces << "   ------>\n";

        cout << "\n\n";
        cout << "箭头正在从右到左移动... (" << MAX_STEPS - i << "/" << MAX_STEPS << ")\n";

        sleepMs(DELAY_MS);
    }
    
    clearScreen();
    cout << "\n\n✓ 箭头移动完成！\n\n";
}

/**
 * 显示菜单
 * 展示所有可选项并提示用户输入
 */
void showMenu() {
    cout << "\n";
    cout << "=================================\n";
    cout << "        图形显示菜单\n";
    cout << "=================================\n";
    cout << "\n";
    cout << "    1. 心形\n";
    cout << "    2. 感叹号\n";
    cout << "    3. 移动的箭头\n";
    cout << "    0. 退出程序\n";
    cout << "\n";
    cout << "=================================\n";
    cout << "请输入你的选择 (0-3): ";
}

// ============== 主程序 ==============

/**
 * 主函数
 * 实现主循环和用户交互
 */
int main() {
    int choice;
    
    // 设置控制台编码（Windows）
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif
    
    // 主循环
    while (true) {
        showMenu();
        cin >> choice;
        
        // 清除输入缓冲区
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                clearScreen();
                cout << "\n>>> 你选择了：心形\n";
                showHeart();
                break;
                
            case 2:
                clearScreen();
                cout << "\n>>> 你选择了：感叹号\n";
                showExclamation();
                break;
                
            case 3:
                clearScreen();
                cout << "\n>>> 你选择了：移动的箭头\n";
                showMovingArrow();
                break;
                
            case 0:
                clearScreen();
                cout << "\n";
                cout << "=================================\n";
                cout << "       感谢使用，再见！\n";
                cout << "=================================\n";
                cout << "\n";
                return 0;
                
            default:
                clearScreen();
                cout << "\n";
                cout << "=================================\n";
                cout << "       ⚠ 无效的选择！\n";
                cout << "=================================\n";
                cout << "\n";
                cout << "请输入 0-3 之间的数字。\n";
                break;
        }
        
        // 暂停等待用户
        pause();
        clearScreen();
    }
    
    return 0;
}
