#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int LEN = 100100;
int n, m, use[LEN], use1[LEN], a, b, f, cnt[LEN], sum[LEN];
ll res;

vector <int> ed[LEN];

void dfs(int v, int p, ll kol)
{
    int u;

    use[v] = 1;
    for (int i = 0; i < ed[v].size(); i++)
    {
        u = ed[v][i];
        if (u == p)
            continue;

        if (!use[u])
            dfs(u, v, kol + 1);

        if (use[u] == 1)
        {
            if (f)
            {
                f = 0;
                res += kol * (1 + (kol - 1) / 2) * ((kol - 1) / 2);
                if ((kol - 1) % 2)
                    res += kol * (kol / 2);
            }

            return;
        }
    }

    use[v] = 2;
}

void dfs1(int v, int p)
{
    int u;

    use1[v] = 1;

    cnt[v] = 1;
    for (int i = 0; i < ed[v].size(); i++)
    {
        u = ed[v][i];
        if (!use1[u])
            dfs1(u, v);

        if (u != p)
        {
            cnt[v] += cnt[u];
            sum[v] += sum[u] + cnt[u];
        }
    }

    for (int i = 0; i < ed[v].size(); i++)
    {
        u = ed[v][i];
        if (u == p)
            continue;
        if (ed[v].size() == 1 || (ed[v].size() == 2 && p != -1))
            res += 2 * (sum[u] + cnt[u]) * (cnt[v] - cnt[u]) + sum[v] - sum[u] - cnt[u];
        else
            res += (sum[u] + cnt[u]) * (cnt[v] - cnt[u]) + sum[v] - sum[u] - cnt[u];
    }

}

int main()
{
    freopen("islands.in", "r", stdin);
    freopen("islands.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        ed[a - 1].push_back(b - 1);
        ed[b - 1].push_back(a - 1);
    }


    for (int i = 0; i < n; i++)
        if (!use[i])
        {
            f = 1;
            dfs(i, -1, 1);
        }

    for (int i = 0; i < n; i++)
        if (use[i] == 2 && !use1[i])
            dfs1(i, -1);

    cout << res;

    return 0;
}
