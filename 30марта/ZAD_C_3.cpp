#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 2000000100000000000;
vector <ll> a[100010], w[100010], ch[100010];
ld dps[2][100010], dpk[2][100010], ss = 0, kl = 0;
ll dfs(ll v, ll p);
int main()
{
    //freopen("tree.in", "r", stdin);
    //freopen("tree.out", "w", stdout);
    ll n, i, x, y, z, t;
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        scanf("%I64d%I64d%I64d%I64d", &x, &y, &z, &t);
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
        ch[x].push_back(t);
        ch[y].push_back(t);
    }
    dfs(0, -1);
    cout << kl << endl;
    if (kl > 0)
        cout << fixed << setprecision(11) << ss / kl << endl;
    else
        cout << 0 << endl;
}

ll dfs(ll v, ll p)
{
    ll i;
    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] != p)
        {
            if (ch[v][i])
            {
                ss += dps[0][v] * dpk[0][a[v][i]] + dps[0][a[v][i]] * dpk[0][v] + ld(w[v][i]) * dpk[0][a[v][i]] * dpk[0][v];
                kl += dpk[0][a[v][i]] * dpk[0][v];// g g

                ss += dps[0][v] * dpk[1][a[v][i]] + dps[1][a[v][i]] * dpk[0][v] + ld(w[v][i]) * dpk[1][a[v][i]] * dpk[0][v];
                kl += dpk[1][a[v][i]] * dpk[0][v];// g ch

                ss += dps[1][v] * dpk[0][a[v][i]] + dps[0][a[v][i]] * dpk[1][v] + ld(w[v][i]) * dpk[0][a[v][i]] * dpk[1][v];
                kl += dpk[0][a[v][i]] * dpk[1][v];// ch g

                ss += dps[1][v] * dpk[1][a[v][i]] + dps[1][a[v][i]] * dpk[1][v] + ld(w[v][i]) * dpk[1][a[v][i]] * dpk[1][v];
                kl += dpk[1][a[v][i]] * dpk[1][v];// ch ch

                ss += dps[0][v] + w[v][i] * dpk[0][v];
                kl += dpk[0][v]; // g

                ss += dps[1][v] + w[v][i] * dpk[1][v];
                kl += dpk[1][v]; // ch

                dps[1][v] += dps[0][a[v][i]] + ld(w[v][i]) * dpk[0][a[v][i]];
                dpk[1][v] += dpk[0][a[v][i]];
                dps[1][v] += dps[1][a[v][i]] + ld(w[v][i]) * dpk[1][a[v][i]];
                dpk[1][v] += dpk[1][a[v][i]];

                dps[1][v] += w[v][i];
                dpk[1][v] += 1.0;
            }

            else
            {
                ss += dps[0][v] * dpk[1][a[v][i]] + dps[1][a[v][i]] * dpk[0][v] + ld(w[v][i]) * dpk[1][a[v][i]] * dpk[0][v];
                kl += dpk[1][a[v][i]] * dpk[0][v];// g ch

                ss += dps[1][v] * dpk[0][a[v][i]] + dps[0][a[v][i]] * dpk[1][v] + ld(w[v][i]) * dpk[0][a[v][i]] * dpk[1][v];
                kl += dpk[0][a[v][i]] * dpk[1][v];// ch g

                ss += dps[1][v] * dpk[1][a[v][i]] + dps[1][a[v][i]] * dpk[1][v] + ld(w[v][i]) * dpk[1][a[v][i]] * dpk[1][v];
                kl += dpk[1][a[v][i]] * dpk[1][v];// ch ch

                ss += dps[1][v] + w[v][i] * dpk[1][v];
                kl += dpk[1][v]; // ch

                dps[0][v] += dps[0][a[v][i]] + ld(w[v][i]) * dpk[0][a[v][i]];
                dpk[0][v] += dpk[0][a[v][i]];
                dps[1][v] += dps[1][a[v][i]] + ld(w[v][i]) * dpk[1][a[v][i]];
                dpk[1][v] += dpk[1][a[v][i]];

                dps[0][v] += w[v][i];
                dpk[0][v] += 1.0;
            }
        }
    ss += dps[1][v];
    kl += dpk[1][v];
}

/*
3
1 2 1 1
1 3 1 1
*/

