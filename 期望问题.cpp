#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
const double EPS = 1e-9;

int n, m;
vector<int> adj[MAXN];
int deg[MAXN];
double a[MAXN * MAXN][MAXN * MAXN]; // 高斯消元的增广矩阵
int idx; // 用于给状态编号

// 高斯消元模板
void gauss(int n) {
    for (int i = 0; i < n; ++i) {
        int r = i;
        for (int j = i + 1; j < n; ++j)
            if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
        if (fabs(a[r][i]) < EPS) continue;
        if (r != i) swap(a[i], a[r]);
        double div = a[i][i];
        for (int j = i; j <= n; ++j) a[i][j] /= div;
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            double factor = a[j][i];
            for (int k = i; k <= n; ++k)
                a[j][k] -= factor * a[i][k];
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // 城市编号从0开始，方便处理
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    // 为每个城市作为起点分别求解
    for (int s = 0; s < n; ++s) {
        // 给每个有向状态 (u, v) 分配一个唯一的编号
        map<pair<int, int>, int> state_id;
        idx = 0;
        for (int u = 0; u < n; ++u) {
            for (int v : adj[u]) {
                if (state_id.find({u, v}) == state_id.end()) {
                    state_id[{u, v}] = idx++;
                }
            }
        }

        // 初始化增广矩阵
        memset(a, 0, sizeof(a));
        for (auto &p : state_id) {
            int u = p.first.first;
            int v = p.first.second;
            int id = p.second;

            // 如果是起点状态 (s, *) 即 u == s
            // 起点方程：E[s][prev] = 1 + 1/deg[s] * sum_{w in adj[s]} E[w][s]
            if (u == s) {
                a[id][id] = 1.0;
                a[id][idx] = 1.0; // 常数项为 1
                for (int w : adj[u]) {
                    int nid = state_id[{w, u}];
                    a[id][nid] -= 1.0 / deg[u];
                }
            } else {
                // 非起点状态方程：E[u][v] = 1 + 1/(deg[u]-1) * sum_{w in adj[u], w != v} E[w][u]
                a[id][id] = 1.0;
                a[id][idx] = 1.0; // 常数项为 1
                for (int w : adj[u]) {
                    if (w == v) continue;
                    int nid = state_id[{w, u}];
                    a[id][nid] -= 1.0 / (deg[u] - 1);
                }
            }
        }

        // 高斯消元
        gauss(idx);

        // 起点 s 的答案：如果起点s有多个邻居，则答案是 (1 + 1/deg[s] * sum_{w in adj[s]} E[w][s])
        // 这里我们直接计算一下，因为s的状态可能没有直接编号
        double ans = 1.0;
        for (int w : adj[s]) {
            int nid = state_id[{w, s}];
            ans += 1.0 / deg[s] * a[nid][idx];
        }
        cout << fixed << setprecision(12) << ans << endl;
    }

    return 0;
}