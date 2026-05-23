#include <bits/stdc++.h>

using namespace std;

// 显示心形
void showHeart() {
    cout << "\n\n";
    cout << "            *****         *****\n";
    cout << "          *********     *********\n";
    cout << "         ************ ************\n";
    cout << "        ***************************\n";
    cout << "        ***************************\n";
    cout << "         *************************\n";
    cout << "          ***********************\n";
    cout << "           *********************\n";
    cout << "            *******************\n";
    cout << "              ***************\n";
    cout << "                ***********\n";
    cout << "                  *******\n";
    cout << "                    ***\n";
    cout << "                     *\n";
    cout << "\n";
}

// 显示感叹号
void showExclamation() {
    cout << "\n\n";
    cout << "      ***\n";
    cout << "      ***\n";
    cout << "      ***\n";
    cout << "      ***\n";
    cout << "      ***\n";
    cout << "      ***\n";
    cout << "      ***\n";
    cout << "      ***\n";
    cout << "      ***\n";
    cout << "      ***\n";
    cout << "\n";
    cout << "     *** ***\n";
    cout << "    ***   ***\n";
    cout << "   ***     ***\n";
    cout << "  ***       ***\n";
    cout << "\n";
}

// 显示移动的箭头
void showMovingArrow() {
    string spaces = "";
    
    // 从左到右移动
    for (int i = 0; i < 40; i++) {
        system("cls");  // 清屏
        
        cout << "\n\n\n\n";
        cout << spaces << "  /\n";
        cout << spaces << " /_\n";
        cout << spaces << "|  |\n";
        cout << spaces << "|__|\n";
        
        cout << "\n\n";
        cout << "箭头正在从左向右移动...\n";
        
        spaces += " ";
        Sleep(100);  // 延迟 100 毫秒
    }
    
    // 从右到左移动
    for (int i = 0; i < 40; i++) {
        system("cls");
        
        cout << "\n\n\n\n";
        cout << spaces << "  /\n";
        cout << spaces << " /_\n";
        cout << spaces << "|  |\n";
        cout << spaces << "|__|\n";
        
        cout << "\n\n";
        cout << "箭头正在从右向左移动...\n";
        
        if (spaces.length() > 0) {
            spaces.pop_back();
        }
        Sleep(100);
    }
    
    system("cls");
    cout << "\n\n移动完成！\n\n";
}

// 显示菜单
void showMenu() {
    cout << "\n";
    cout << "=================================\n";
    cout << "        图形显示菜单\n";
    cout << "=================================\n";
    cout << "\n";
    cout << "    1. 心形\n";
    cout << "    2. 感叹号\n";
    cout << "    3. 移动的箭头\n";
    cout << "    0. 退出\n";
    cout << "\n";
    cout << "=================================\n";
    cout << "请输入你的选择 (0-3): ";
}

int main() {
    int choice;
    
    // 设置控制台编码为 UTF-8 (Windows)
    system("chcp 65001 > nul");
    
    while (true) {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                system("cls");
                cout << "\n你选择了：心形\n";
                showHeart();
                break;
                
            case 2:
                system("cls");
                cout << "\n你选择了：感叹号\n";
                showExclamation();
                break;
                
            case 3:
                system("cls");
                cout << "\n你选择了：移动的箭头\n";
                showMovingArrow();
                break;
                
            case 0:
                system("cls");
                cout << "\n感谢使用，再见！\n\n";
                return 0;
                
            default:
                system("cls");
                cout << "\n无效的选择，请重新输入！\n";
                break;
        }
        
        // 暂停，等待用户按任意键
        cout << "\n按 Enter 键继续...";
        cin.ignore();
        cin.get();
        system("cls");
    }
    
    return 0;
}
