#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
ll a[110], b[110], c[110], d[110];
int main()
{
    freopen("jedivssith.in", "r", stdin);
    freopen("jedivssith.out", "w", stdout);
    ll i, j, n, mn = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%I64d", &b[i]);
    for (i = 0; i < n; i++)
        scanf("%I64d", &c[i]);
    for (i = 0; i < n; i++)
        scanf("%I64d", &d[i]);
    for (i = 0; i < n; i++)
    {
        if (a[i] < c[i])
        {
            if (b[i] > d[i])
                mn = max(mn, (c[i] - a[i] - 1) / (b[i] - d[i]) + 1);
            else
            {
                mn = INF;
                break;
            }
        }
    }
    if (mn == INF)
    {
        cout << "Strong is dark side of the force.\n";
        return 0;
    }
    for (i = 0; i < n; i++)
        if (a[i] + b[i] * mn < c[i] + d[i] * mn)
        {
            cout << "Strong is dark side of the force.\n";
            return 0;
        }
    cout << mn << endl;
    return 0;
}
