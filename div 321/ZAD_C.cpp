#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector <int> a[100010];
bool b[100010];
int sum, m, ans;
void dfs(int v, int p, int sum);
int main()
{
    int i, n, x, y;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        b[i] = bool(x);
    }

    for (i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(0, -1, 0);
    cout << ans << endl;
    return 0;
}

void dfs(int v, int p, int sum)
{
    int s = 0, i;
    if (b[v])
        sum++;
    else
        sum = 0;
    if (sum > m)
        return;
    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] != p)
        {
            s++;
            dfs(a[v][i], v, sum);
        }
    if ((!s) && (sum <= m))
        ans++;
}
