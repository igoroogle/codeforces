#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
ll a[100010];
int main()
{
    ll l, r, n, k, i, m, sm;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    l = 0;
    r = n;
    while (l < r)
    {
        m = (l + r) >> ll(1);
        sm = m * ll(m + 1) >> ll(1);
        if (sm < k)
            l = m + ll(1);
        else
            r = m;
    }
    m = l - 1;
    sm = m * ll(m + 1) >> ll(1);
    k -= sm;
    cout << a[k] << endl;
    return 0;
}
