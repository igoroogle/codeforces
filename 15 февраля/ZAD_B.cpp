#include <bits/stdc++.h>
using namespace std;
const int INF = 2E9;
char a[1001][1001];
int hp[1001], hm[1001], hv[1001], wp[1001], wm[1001], wv[1001];
int main()
{
    freopen("protocol.in", "r", stdin);
    freopen("protocol.out", "w", stdout);
    int n, m, i, j, mx = -INF;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        scanf("\n");
        for (j = 0; j < m; j++)
            scanf("%c", &a[i][j]);
    }

    /*for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << a[i][j];
        cout << endl;
    }*/

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == '+')
            {
                wp[i]++;
                hp[j]++;
            }

            else if (a[i][j] == '-')
            {
                wm[i]++;
                hm[j]++;
            }

            else if (a[i][j] == '?')
            {
                wv[i]++;
                hv[j]++;
            }
        }

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != '?')
            {
                mx = max(mx, wp[i] - wm[i] + wv[i] - (hp[j] - hm[j] - hv[j]));
                continue;
            }
            mx = max(mx, wp[i] - wm[i] + wv[i] - 1 - (hp[j] - hm[j] - hv[j] + 1));
        }
    cout << mx << endl;
    return 0;
}


/*
2 1
Russia Russia go go go
Russia Russia lets go
*/
