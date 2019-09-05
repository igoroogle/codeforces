#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000000;
int known[4003], a[4003], b[4003];
bool d[4003][4003];
int main()
{
    int n, m, i, j, x, y, mn = INF;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        d[x][y] = 1;
        d[y][x] = 1;
        known[x]++;
        known[y]++;
        a[i] = x;
        b[i] = y;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if ((a[j] != i) && (b[j] != i) && (d[i][a[j]]) && (d[i][b[j]]))
                mn = min(mn, known[i] + known[a[j]] + known[b[j]] - 6);
    if (mn == INF)
        cout << -1 << endl;
    else
        cout << mn << endl;
    return 0;
}

