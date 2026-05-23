#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    int r;
} nd[100005];

int head, n;
int val[100005];
int cnt;

int main() {
    cin >> head >> n;
    int id, num, nxt;
    for (int i = 0; i < n; ++i) {
        cin >> id >> num >> nxt;
        nd[id].val = num;
        nd[id].r = nxt;
    }
    for (int i = head; i != -1; i = nd[i].r) {
        val[++cnt] = i;
    }
    int l = 1, r = cnt；
    while (l < r) {
        printf("%05d %d %05d\n", val[r], nd[val[r]].val, val[l]);
        r--;
        if (l < r) {
            printf("%05d %d %05d\n", val[l], nd[val[l]].val, val[r]);
            l++;
        }
    }
    if (l == r) {
        printf("%05d %d -1\n", val[l], nd[val[l]].val);
    }
    return 0;
}