#include <bits/stdc++.h>

#define PII pair <int, int>

using namespace std;

const int M = 450;
const int N = 30;
const double eps = 1e-12;

int n, m;

struct node
{
    int to, nxt;
}e[M];

int head[N], idx;

int deg[N];
int id[N][N], total;
PII edge[M];

double matrix[M][M];
double solution[M];

inline void add(int u, int v)
{
    e[idx].to = v;
    e[idx].nxt = head[u];
    head[u] = idx++;
    deg[u]++;
    id[u][v] = ++total;
    edge[total] = {u, v};
}

inline void gauss(int total)
{
    for (int i = 1; i <= total; ++i)
    {
        int maxidx = i;

        for (int j = i + 1; j <= total; ++j)
        {
            if (fabs(matrix[j][i]) > fabs(matrix[maxidx][i])) maxidx = j;
        }

        if (maxidx != i)
        {
            for (int j = 1; j <= total + 1; ++j) swap(matrix[i][j], matrix[maxidx][j]);
        }

        double div = matrix[i][i];

        for (int j = i; j <= total + 1; ++j)
        {
            matrix[i][j] /= div;
        }

        for (int j = 1; j <= total; ++j)
        {
            if (i == j) continue;

            double mul = matrix[j][i];

            for (int k = i; k <= total + 1; ++k)
            {
                matrix[j][k] -= mul * matrix[i][k];
            }
        }
    }

    for (int i = 1; i <= total; ++i) solution[i] = matrix[i][total + 1];
}

int main()
{
    scanf("%d %d", &n, &m);

    memset(head, -1, sizeof head);

    for (int i = 1; i <= m; ++i)
    {
        int u, v; scanf("%d %d", &u, &v);
        add(u, v); add(v, u);
    }

    for (int start = 1; start <= n; ++start)
    {
        memset(matrix, 0, sizeof matrix);

        for (int i = 1; i <= total; ++i)
        {
            int u = edge[i].first, v = edge[i].second;

            matrix[i][i] = 1.0;

            if (v == start) matrix[i][total + 1] = 0.0;
            else
            {
                matrix[i][total + 1] = 1.0;

                int choice = deg[v] - 1;
                double prob = 1.0 / choice;

                for (int j = head[v]; ~j; j = e[j].nxt)
                {
                    int to = e[j].to;

                    if (to == u) continue;

                    int nxtid = id[v][to];

                    matrix[i][nxtid] -= prob;
                }
            }
        }

        gauss(total);

        double ans = 0;

        for (int i = head[start]; ~i; i = e[i].nxt)
        {
            int v = e[i].to;
            int num = id[start][v];
            ans += (1.0 + solution[num]);
        }

        ans /= (double)deg[start];

        printf("%.12lf\n", ans);
    }

    return 0;
}
