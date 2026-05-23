#include <bits/stdc++.h>
using namespace std;

int maxCover(vector<pair<int,int>>& intervals){
    vector<pair<int, int>> events; // (position, delta)
    for (auto& [l, r] : intervals) {
        events.emplace_back(l, 1);
        events.emplace_back(r, -1);
    }
    // 排序：坐标升序，相同坐标时 +1 在前
    sort(events.begin(), events.end(), [](auto& a, auto& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second; // 1 > -1
    });
    int cur = 0, ans = 0;
    for (auto& [pos, delta] : events) {
        if (delta == 1) {
            cur++;
            ans = max(ans, cur);
        } else {
            ans = max(ans, cur);
            cur--;
        }
    }
    return ans;
}