#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int rows;
    cout << "请输入爱心的行数（10~100行最佳）: ";
    cin >> rows;

    // 根据行数计算合适的步长
    double yStep = 3.0 / rows;      // y轴步长
    double xStep = yStep / 2.0;      // x轴步长（保持2:1宽高比）

    for (double y = 1.5; y >= -1.5; y -= yStep) {
        for (double x = -1.5; x <= 1.5; x += xStep) {
            // 心形方程：(x² + y² - 1)³ - x² * y³ ≤ 0
            double a = x * x + y * y - 1;
            if (a * a * a - x * x * y * y * y <= 0.0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
