#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tim[110], backt[110];
bool use[110];
vector<int> a[110];
bool kuhn(int v, int p, int t);
int main()
{
    freopen("contest.in", "r", stdin);
    freopen("contest.out", "w", stdout);
    int n, m, t, l, i, j, p, k, x, mnt  = 0, mx = 0, sm = 0;
    cin >> n >> m >> t >> l;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        for (j = 0; j < k; j++)
        {
            scanf("%d", &x);
            a[i].push_back(x - 1);
        }
    }
    for (i = l; i <= t; i = i + l)
    {
        for (j = 0; j < n; j++)
            use[j] = 0;
        sm = 0;
        for (j = 0; j < n; j++)
            {
                for (p = 0; p < n; p++)
                    use[p] = 0;
                sm += int(kuhn(j, -1, i));
            }
        if (sm == 0)
            break;
        mx += sm;
        mnt += i * sm;
    }
    cout << mx << ' ' << mnt << endl;
    return 0;
}

bool kuhn(int v, int p, int t)
{
    if (use[v])
        return 0;
    use[v] = 1;
    int i;
    for (i = 0; i < a[v].size(); i++)
        if ((a[v][i] != p) && ((tim[a[v][i]] == 0) || ((tim[a[v][i]] == t) && (kuhn(backt[a[v][i]], a[v][i], t)))))
        {
            backt[a[v][i]] = v;
            tim[a[v][i]] = t;
            return 1;
        }
    return 0;
}
