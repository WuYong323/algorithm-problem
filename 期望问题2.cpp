#include <bits/stdc++.h>
using namespace std;

const int N = 25;
const double EPS = 1e-12;

int n, m;
vector<int> adj[N];
int deg[N];

int id[N][N];                     // id[u][v]：当前在 u，上一步来自 v 的状态编号
int total_states;
pair<int, int> state_of[2 * N * N]; // 反查

double mat[2 * N * N][2 * N * N];
double ans_vec[2 * N * N];

void gauss(int n) {
    for (int i = 1; i <= n; ++i) {
        int r = i;
        for (int j = i + 1; j <= n; ++j)
            if (fabs(mat[j][i]) > fabs(mat[r][i])) r = j;
        if (fabs(mat[r][i]) < EPS) continue;
        if (r != i) swap(mat[i], mat[r]);
        double div = mat[i][i];
        for (int j = i; j <= n + 1; ++j) mat[i][j] /= div;
        for (int j = 1; j <= n; ++j) {
            if (j == i) continue;
            double factor = mat[j][i];
            for (int k = i; k <= n + 1; ++k)
                mat[j][k] -= factor * mat[i][k];
        }
    }
    for (int i = 1; i <= n; ++i) ans_vec[i] = mat[i][n + 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    // 给状态编号：(u, v) 表示当前在 u，上一步来自 v
    total_states = 0;
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            id[u][v] = ++total_states;
            state_of[total_states] = {u, v};
        }
    }

    for (int start = 1; start <= n; ++start) {
        memset(mat, 0, sizeof(mat));

        for (int i = 1; i <= total_states; ++i) {
            int u = state_of[i].first;   // 当前城市
            int v = state_of[i].second;  // 上一步来自的城市

            mat[i][i] = 1.0;

            // 如果已经回到起点（即当前城市 u 就是起点），期望为 0
            if (u == start) {
                mat[i][total_states + 1] = 0.0;
            } else {
                mat[i][total_states + 1] = 1.0;   // 走一步的代价

                int choices = deg[u] - 1;
                double prob = 1.0 / choices;

                for (int w : adj[u]) {
                    if (w == v) continue;         // 不能原路返回
                    int next_id = id[w][u];       // 关键修正：下一状态是 (w, u)
                    mat[i][next_id] -= prob;
                }
            }
        }

        gauss(total_states);

        // 从起点出发，第一步走到邻居 w
        double ans = 0.0;
        for (int w : adj[start]) {
            int state_id = id[w][start];         // 注意：第一步行走到 w，上一步是 start
            ans += ans_vec[state_id];            // 这里不要加 1.0，因为方程常数项已含第一步
        }
        ans = ans / deg[start] + 1.0;            // 或者更清晰：平均第一步的后续期望，再加 1

        // 上面两行等价于标准代码的 ans += (1.0 + solution[num]) / deg
        // 为了更清晰，可以直接写：
        // double ans = 0;
        // for (int w : adj[start])
        //     ans += 1.0 + ans_vec[id[w][start]];
        // ans /= deg[start];

        cout << fixed << setprecision(12) << ans << endl;
    }

    return 0;
}