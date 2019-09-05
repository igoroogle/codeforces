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
const int N = 300001;
const int M = 1001;
typedef long long ll;
int a[2049];
int main()
{
    freopen("relatives.in", "r", stdin);
    freopen("relatives.out", "w", stdout);
    ll ans = 0;
    int n, i, j, p, x, vl;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        j = x;
        vl = 0;
        while (j > 0)
        {
            vl = vl | (1 << (j % 10));
            j /= 10;
        }
        if (vl == 0)
            vl = 1;
        a[vl]++;
    }
    for (i = 1; i < (1 << 10); i++)
        {
            if (a[i] > 1)
                ans += ll(a[i]) * ll(a[i] - 1) / ll(2);
            for (j = 0; j < i; j++)
                for (p = 0; p < 10; p++)
                    if ((1 << p) & i & j)
                    {
                        ans += ll(a[i]) * ll(a[j]);
                        break;
                    }
        }
    cout << ans << endl;
    return 0;
}
