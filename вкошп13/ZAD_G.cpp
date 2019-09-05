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
#define NAME "prizes"
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




int main()
{
    FREOPEN;
    ll nn, mm, n, m;
    cin >> nn >> mm;
    n = min(nn, mm);
    m = max(nn, mm);
    if (n == 1)
    {
        ll sum = 0;
        if (m <= 2)
            cout << 0;
        else
        {
            m -= 2;
            cout << m / 4 + (m % 4 == 0 ? 0 : 1);
        }
    }
    else
    {
        ll sum = 0;
        if (n <= 2)
            cout << 0;
        else
        {
            n -= 2;
            cout << 1;
        }
    }



    return 0;
}

/*



*/

