#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 998244353;

i64 f[maxn], g[maxn];
i64 ksm(i64 a, i64 n) {
    i64 ans = 1;
    a %= mod;
    while (n) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

void init() {
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * ksm(i, mod - 2) % mod;
    }
}

inline i64 C(i64 n, i64 m) {
    if (m > n || n < 0 || m < 0) {
        return 0;
    }
    if (m == 0) {
        return 1;
    }
    return f[n] * g[m] % mod * g[n - m] % mod;
}

vector<pair<int, int>> coo[maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<int> cnt(n * m + 1);
    int B = sqrtl(n * m);
    for (int i = 1; i <= n * m; i++) {
        // coo[i].swap(vector<pair<int, int>>());
        vector<pair<int, int>>().swap(coo[i]);
    }
    // vector<vector<pair<int, int>>> coo(n * m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
            if (cnt[a[i][j]] <= B) {
                coo[a[i][j]].emplace_back(i, j);
            }
        }
    }

    i64 ans = 0;
    for (int o = 1; o <= n * m; o++) {
        if (cnt[o] > B) {
            vector<vector<i64>> dp(n + 1, vector<i64>(m + 1));
            dp[1][0] = 1;
            i64 res = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    dp[i][j] = (dp[i - 1][j] * (a[i - 1][j] != o) + 
                        dp[i][j - 1] * (a[i][j - 1] != o)) % mod;
                    if (a[i][j] == o) {
                        res = (res + dp[i][j] * C(n - i + m - j, n - i)) % mod;
                    }
                }
            }
            ans = (ans + res) % mod;
        } else {
            auto &v = coo[o];
            sort(v.begin(), v.end());
            vector<i64> dp(v.size());
            for (int i = 0; i < v.size(); i++) {
                dp[i] = C(v[i].first + v[i].second - 2, v[i].first - 1);
                for (int j = 0; j < i; j++) {
                    if (v[j].first <= v[i].first && v[j].second <= v[i].second) {
                        dp[i] = (dp[i] - dp[j] * C(
                            v[i].first - v[j].first + v[i].second - v[j].second, 
                            v[i].first - v[j].first
                        ) % mod + mod) % mod;
                    }
                }
            }
            i64 res = 0;
            for (int i = 0; i < dp.size(); i++) {
                res = (res + dp[i] * C(
                    n - v[i].first + m - v[i].second, 
                    n - v[i].first
                )) % mod;
            }
            ans = (ans + res) % mod;
        }
    }
    cout << ans << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}