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
const int N = 1000001;
const int M = 1001;

int n, r[N], q;
pair <pll, int> a[N];

bool comp(pair <pll, int> a, pair <pll, int> b)
{
    return (a.x.x + a.x.y) / 2 < (b.x.x + b.x.y) / 2;
}

ll rast(pair <pll, int> a, pair <pll, int> b)
{
    return abs(a.x.x - b.x.x) + abs(a.x.y - a.x.y);
}

int main()
{
    //freopen("ads.in", "r", stdin);
    //freopen("river.out", "w", stdout);
    cin >> n;
    forn(i, n)
    {
        scanf("%I64d %I64d", &a[i].x.y, &a[i].x.x);
        a[i].y = i + 1;
    }

    ll x;
    forn(i, 100000000)
    {
        x = ((ll)rand() * (ll)rand()) % n;
        if (x < 2 || x >= n - 2)
            continue;
        if (rast(a[i - 1], a[i]) + rast(a[i], a[i + 1]) + rast(a[i + 1], a[i + 2]) > rast(a[i - 1], a[i + 1]) + rast(a[i + 1], a[i + 2]) + rast(a[i], a[i + 2]))
            swap(a[i], a[i + 1]);
    }

    forn(i, n)
        printf("%d ", a[i].y);
    return 0;
}
