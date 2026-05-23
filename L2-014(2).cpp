#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> tails; // 存储每条轨道最后一辆列车的编号，保持递增
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        auto it = upper_bound(tails.begin(), tails.end(), x);
        if (it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }
    printf("%d\n", (int)tails.size());
    return 0;
}