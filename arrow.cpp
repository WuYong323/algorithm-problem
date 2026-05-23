#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    int width = 50;  // 终端宽度
    string arrow = "----->";  // 箭头形状

    cout << "箭头射星动画开始！" << endl;
    cout << "按任意键继续..." << endl;
    cin.get();

    for (int i = 0; i <= width - arrow.length(); i++) {
        // 清除当前行
        cout << "\r";

        // 打印左边的空格（箭头移动）
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        // 打印箭头（形状固定）
        cout << arrow;

        // 打印中间的空格
        for (int j = i + arrow.length(); j < width - 1; j++) {
            cout << " ";
        }

        // 打印右边的星号
        cout << "*" << flush;

        // 延时
        Sleep(50);

        // 射中星号时停止
        if (i >= width - arrow.length() - 1) {
            cout << endl << "命中目标！" << endl;
            break;
        }
    }

    cout << "按任意键退出...";
    cin.get();
    return 0;
}
