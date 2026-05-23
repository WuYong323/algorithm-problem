#include <iostream>
#include <cmath>
using namespace std;

int main() {
    for (double y = 1.5; y >= -1.5; y -= 0.06) {
        for (double x = -1.5; x <= 1.5; x += 0.03) {
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
