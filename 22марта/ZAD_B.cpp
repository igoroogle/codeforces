#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1E18 + 40;
const ll DL = 1000100;
ll r[100010], s[100010], t[100010];
int main()
{
    freopen("thereturn.in", "r", stdin);
    freopen("thereturn.out", "w", stdout);
    ll n, l, i, vl, ans = 0, vv;
    cin >> n >> l;

    for (i = 0; i < n; i++)
        scanf("%I64d%I64d%I64d", &r[i], &s[i], &t[i]);

    for (i = 0; i < n; i++)
    {
        if (l == 1)
            {
                ans++;
                continue;
            }
        else
        {
            vl = (s[i] - 1) % (l + l - 2);
            vl++;
        }
        if (vl > l)
        {
            if (l - (vl - l) >= r[i])
            {
                if (l - (vl - l) - r[i] <= t[i])
                    ans++;
                continue;
            }

            vv = l - 1 - (vl - l);
            if (vv + r[i] - 1 <= t[i])
                ans++;
            continue;
        }

        if (vl <= r[i])
        {
            if (r[i] - vl <= t[i])
                ans++;
            continue;
        }

        vv = l - vl;
        if (vv + l - r[i] <= t[i])
            ans++;
    }

    cout << ans << endl;
    return 0;
}

/*
5 4
2 1 2
4 1 1
3 1 2
4 3 3
1 1 6
*/
