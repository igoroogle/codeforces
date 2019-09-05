#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "fence"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 2e9;
const ll INF64 = 7e18;
const ld EPS = 1e-9;
const ld PI = 3.14159265358979310000;
const ll MD = 535355424;
const ll T = 34539;
const int N = 300100;
const int M = 301;
typedef long long ll;
ll a[100010], n, k;
ll fun(ll x);
int main()
{
    FREOPEN;
    ll i, l, r, m;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    l = 1;
    r = 1000000010;
    while (l < r)
    {
        m = (l + r) / 2;
        if (fun(m))
            l = m + 1;
        else
            r = m;
    }
    cout << l - 1 << endl;
    return 0;
}

ll fun(ll x)
{
    ll i, s = 0;
    for (i = 0; i < n; i++)
        {
            if (a[i] < x)
                return 0;
            if (a[i] > s + x)
            {
                if ((i == n - 1) && (s + x <= k))
                    return 1;
                s = a[i];
            }
            else
                s += x;
        }
    return (s <= k);
}
