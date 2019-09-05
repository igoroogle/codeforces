#include <bits/stdc++.h>
#define mp mak_pair
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ll n, h, k, i, ans = 0, x, cur = 0, t;
    cin >> n >> h >> k;
    for (i = 0; i < n; i++)
    {
        //cout << cur << endl;
        scanf("%I64d", &x);
        if (cur + x > h)
        {
            //break;
            t = (cur + x - h - ll(1)) / k + ll(1);
            ans += t;
            cur -= t * k;
            cur = max(ll(0), cur);
        }
        //cout << cur << endl;
        cur += x;
    }

    if (cur > 0)
        ans += (cur - ll(1)) / k + ll(1);
    cout << ans << endl;
    return 0;
}
