#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1E18 + 40;
const ll DL = 1000100;
ll h[100010], a[100010], lef[DL], sl[DL], sr[DL], rig[DL], k[DL];
int main()
{
    freopen("fly.in", "r", stdin);
    freopen("fly.out", "w", stdout);
    ll n, i, s, an1 = 0, an2 = INF, ans;
    cin >> n;

    for (i = 0; i < n; i++)
        scanf("%I64d", &h[i]);
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);

    for (i = 0; i < n; i++)
        k[h[i]] += a[i];
    s = 0;

    for (i = 1; i < DL; i++)
    {
        lef[i] = min(lef[i - 1] + sl[i - 1], INF);
        sl[i] = min(sl[i - 1] + k[i], INF);
    }


    for (i = DL - 2; i >= 0; i--)
    {
        rig[i] = min(rig[i + 1] + sr[i + 1], INF);
        sr[i] = min(sr[i + 1] + k[i], INF);
    }

    for (i = 0; i < DL; i++)
    {
        ans = min(lef[i] + rig[i], INF);
        if (ans < an2)
        {
            an2 = ans;
            an1 = i;
        }
    }

    cout << an1 << ' ' << an2 << endl;
    return 0;
}
