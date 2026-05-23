#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound

using namespace std;

int lengthOfLIS(const vector<int>& nums) {
    vector<int> tails;  // tails[k] 表示长度为 k+1 的递增子序列的最小末尾值
    for (int x : nums) {
        // 在 tails 中找第一个 >= x 的位置
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            // x 大于所有已有末尾值，可以扩展出更长的子序列
            tails.push_back(x);
        } else {
            // 替换，保持 tails 的递增性质
            *it = x;
        }
    }
    return tails.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS: " << lengthOfLIS(nums) << endl;  // 输出 4
    return 0;
}