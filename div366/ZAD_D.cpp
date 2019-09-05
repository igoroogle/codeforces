#include<bits/stdc++.h>
#define y first
#define x second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
const ll DL = 5002;
ll x[DL], a[DL], b[DL], c[DL], d[DL],  v[DL][DL], rs[DL];
bool use[DL];
ll ras(ll v1, ll i, ll v2, ll j);
int main()
{
    ll n, s, e, i, j, ind;
    cin >> n >> s >> e;
    s--;
    e--;
    for (i = 0; i < n; i++)
        scanf("%I64d", &x[i]);

    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);

    for (i = 0; i < n; i++)
        scanf("%I64d", &b[i]);

    for (i = 0; i < n; i++)
        scanf("%I64d", &b[i]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                v[i][j] = 0;
                continue;
            }

            if(j < i)
                v[i][j] = ll(abs(x[i] - x[j])) + c[i] + b[j];
            else
                v[i][j] = ll(abs(x[i] - x[j])) + d[i] + a[j];
        }

    for (i = 0; i < n; i++)
        rs[i] = INF;

    rs[s] = 0;
    for(;;)
    {
        ind = -1;
        for (i = 0; i < n; i++)
            if ((!use[i]) && (rs[i] < INF) && ((ind == -1) || (rs[ind] > rs[i])))
                ind = i;

        if (ind == -1)
            break;
        use[ind] = 1;

        for (i = 0; i < n; i++)
            if ((!use[i]) && (rs[ind] + v[ind][i] < rs[i]))
                rs[i] = rs[ind] + v[ind][i];

    }

    cout << rs[e] << endl;

    return 0;
}
