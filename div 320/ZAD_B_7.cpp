#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int DL = 200005;
ll n, k, x, a[DL], d[DL][13], s[DL];
int main()
{
    cin >> n >> k >> x;
    ll q = 1;
    for (int i = 0; i <= k; i++)
        q *= x;

    s[0] = 1;
    for (int i = 1; i <= k; i++)
        s[i] = s[i - 1] * x;


    for( int i = 0; i < n; i++)
    {
        scanf("%I64d", &a[i]);
    }
    for (int i = 0; i < k + 1; i++)
        d[0][i] = a[0] * s[i];


    for (int i = 1; i < n; i++)
        for (int j = 0; j < k + 1; j++)
            for (int u = 0; u <= j; u++)
            {
                d[i][j] = max(d[i][j], d[i - 1][u] | (a[i] * s[j - u]));
            }

    ll mx = 0;
    for (int i = 0; i < k + 1; i++)
        mx = max(mx, d[n - 1][i]);
    cout << mx << endl;

    return 0;
}

/*

*/






