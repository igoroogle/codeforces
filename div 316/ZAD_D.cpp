#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 100000000000;
vector <int> a[500010];
int tin[500010], sum[26][500010];
bool use[500010];
string s;
void dfs(int, int);
int main()
{
    int n, m, i, j, x, y, nh;
    cin >> n >> m;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &x);
        x--;
        a[x].push_back(i);
    }
    cin >> s;
    dfs(0, 0);
    for (i = 0; i < n; i++) sum[int(s[tin[i]] - 'a')][tin[i]]++;
    for (i = 0; i < n; i++)
    {
        nh = 0;
        for (j = 0; j < 26; j++)
            if (sum[i][j] % 2) nh++;
        if (nh < 2) use[i] = 1;
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        if (use[tin[x] + y]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
void dfs(int v, int kol)
{
    int i;
    tin[v] = kol;
    for (i = 0; i < a[v].size(); i++) dfs(a[v][i], kol + 1);
}
