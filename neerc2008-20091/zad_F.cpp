#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(a) ((a) * (a))
#define forn(i, n) for(int i = 0; i < int(n); i++)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const
    int MOD = 1000000007;

using namespace std;

int z[55], d[55];
int main()
{
    freopen("railway.in", "r", stdin);
    freopen("railway.out", "w", stdout);
    int s, t, c1, c2, c3 ,r, ans1, ans2, v1, v2, n, i;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &d[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &z[i]);
    cin >> s >> t >> c1 >> c2 >> c3 >> r;
    s--;
    t--;
    if (z[s] == z[t]) ans1 = c1;
    else ans1 = abs(z[s] - z[t]) * c1;
    v1 = abs(d[s] - d[t]);
    if (v1 < r)
        ans2 = v1 * c2;
    else
        ans2 = v1 * c3;
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
