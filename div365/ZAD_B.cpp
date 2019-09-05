#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
bool cap[100010];
ll ss[100010], sm[100010], vl[100010];
int main()
{
    ll n, k, x, i, ans = 0;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        scanf("%I64d", &vl[i]);

    while (k--)
    {
        scanf("%I64d", &x);
        x--;
        cap[x] = 1;
    }

    for (i = n - 1; i >= 0; i--)
    {
        sm[i] = sm[i + 1] + vl[i];
        ss[i] = ss[i + 1];
        if (cap[i])
            ss[i] += vl[i];
    }

    for (i = 0; i < n; i++)
    {
        //cout << i << ' ' << sm[i + 1] << ' ' << ss[i + 1] << endl;
        if (cap[i])
            ans += vl[i] * sm[i + 1];
        else
            ans += vl[i] * ss[i + 1];
    }

    for (i = 0; i < n - 1; i++)
        if ((!cap[i]) && (!cap[i + 1]))
            ans += vl[i] * vl[i + 1];

    if ((n > 2) && (!cap[0]) && (!cap[n - 1]))
        ans += vl[0] * vl[n - 1];


    cout << ans << endl;
    return 0;
}
