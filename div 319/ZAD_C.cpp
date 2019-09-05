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

bool comp(int a, int b)
{
    return rand() % 2;
}

int main()
{
    //freopen("ads.in", "r", stdin);
    //freopen("river.out", "w", stdout);
    srand(time(0));
    cin >> n;
    forn(i, n)
    {
        scanf("%I64d %I64d", &a[i].x.y, &a[i].x.x);
        a[i].y = i + 1;
        r[i] = i + 1;
    }
    sort(r, r + n, comp);
    forn(i, n)
        printf("%d ", r[i]);
    return 0;
}
