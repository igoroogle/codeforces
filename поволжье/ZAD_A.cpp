#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 100010;
const int INF = 2000000000;
string a[1002];
int b[1002][1002], d[1002], val[1002];
bool use[1002];
int main()
{
    int ans = 0, i, j, k, n, m, mx, ind;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        val[i] = INF;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i != j)
            {
                mx = 0;
                for (k = 0; k < m; k++)
                    mx = max(mx, abs(int(a[i][k]) - int(a[j][k])));
                val[i] = min(val[i], mx);
                b[i][j] = mx;
            }

    for (i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;
    for (;;)
    {
        ind = -1;
        for (i = 0; i < n; i++)
            if ((!use[i]) && (d[i] < INF) && ((ind == -1) || (d[i] < d[ind])))
                ind = i;
        if (ind == -1)
            break;
        use[ind] = 1;
        for (i = 0; i < n; i++)
            if (!use[i])
                d[i] = min(d[i], max(b[ind][i], d[ind]));
    }
    for (i = 0; i < n; i++)
        ans = max(ans, d[i]);
    cout << ans << endl;
    return 0;
}
