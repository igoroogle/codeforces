#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(a) ((a) * (a))
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const int MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 9e18;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const int N = 20001;
const int M = 3001;
const ll T = 239581;
const ll MD = 1402854021;

int n;
string s, ss;
bool mark[M][M], d[M][M];
ll h1[M][M], h2[M][M], step[M], g[M];


bool rec(int l, int r)
{
    if (l >= r - 1)
        return 1;
    if (mark[l][r])
        return d[l][r];
    int len = r - l + 1;
    if (rec(l, l + len / 2 - 1) && rec(r - len / 2 + 1, r) && h1[l][(len - 1) / 2] == h2[r - (len - 1) / 2][(len - 1) / 2])
        d[l][r] = 1;
    mark[l][r] = 1;
    return d[l][r];
}

int main()
{
    freopen("semipal.in", "r", stdin);
    freopen("semipal.out", "w", stdout);
    cin >> n >> s;
    step[0] = 1;
    for (int i = 1; i < M; i++)
        step[i] = (step[i - 1] * T) % MD;
    ll k;
    forn(i, n)
    {
        forn(j, 300)
            g[j] = 0;
        k = 1;
        ll h = 0;
        for (int j = i; j < n; j++)
        {
            if (j == i)
            {
                g[s[j]] = (ll)1;
                h = 1;
            }
            else
            {
                if (g[s[j]] == 0)
                {
                    k++;
                    g[s[j]] = k;
                }
                h = (h * T + g[s[j]]) % MD;
                h1[i][j - i] = h;
            }
        }
    }

    for (int j = n - 1; j >= 0; j--)
    {
        forn(i, 300)
            g[i] = 0;
        k = 1;
        ll h = 1;
        for (int i = j; i >= 0; i--)
        {
            if (j == i)
            {
                g[s[i]] = (ll)1;
                h = 1;
            }
            else
            {
                if (g[s[i]] == 0)
                {
                    k++;
                    g[s[i]] = k;
                }
                h = (h * T + g[s[i]]) % MD;
                h2[i][j - i] = h;
            }
        }
    }

    int maxi = 1, l = 0, r = 0;
    forn(i, n)
        for (int j = i; j < n; j++)
            if (j - i + 1 > maxi && rec(i, j))
        {
            maxi = j - i + 1;
            l = i;
            r = j;
        }
    for (int u = l; u <= r; u++)
        cout << s[u];
    return 0;
}
