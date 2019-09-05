#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2000000000000000000;
int main()
{
    ll n, ans = 0, i, p, a, mn = INF;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &a, &p);
        mn = min(mn, p);
        ans += mn * a;
    }
    cout << ans << endl;
    return 0;
}
