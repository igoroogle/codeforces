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
typedef unsigned long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 9e18;
const double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const ll MD = 1248742437;
const ll T = 378531;
const int N = 200001;
const int M = 810;

ll n, k, x, a[N], d[N][11], s[N];

int main()
{
    //freopen("ads.in", "r", stdin);
    //freopen("river.out", "w", stdout);
    cin >> n >> k >> x;
    int zz;
    zz = 1;
    ll q = 1;
    forn(i, k)
        q *= x;

    s[0] = 1;
    for (int i = 1; i <= k; i++)
        s[i] = s[i - 1] * x;


    forn(i, n)
    {
        scanf("%I64d", &a[i]);
    }
    forn(i, k + 1)
        d[0][i] = a[0] * s[i];


    for (int i = 1; i < n; i++)
        forn(j, k + 1)
            for (int u = 0; u <= j; u++)
            {
                d[i][j] = max(d[i][j], d[i - 1][u] | (a[i] * s[j - u]));
            }

    ll maxi = 0;
    forn(i, k + 1)
        maxi = max(maxi, d[n - 1][i]);
    cout << maxi << endl;

    return 0;
}

/*

*/






