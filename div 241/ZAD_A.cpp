#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
ll a[100010];
int main()
{
    ll n, m = 0, i, ans = 0, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d", &x);
        if (!(x % 2))
            ans += x;
        else
            a[m++] = x;
    }

    if (m > 1)
        sort(a, a + m);
    reverse(a, a + m);
    if (m % 2)
        m--;
    for (i = 0; i < m; i++)
        ans += a[i];
    cout << ans << endl;
    return 0;
}
