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
#define NAME "sochi"
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

const int LEN = 100100;
int a[LEN], sum, d, n, res;

int main()
{
    FREOPEN;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    if (n == 1)
    {
        cout << a[n - 1];
        return 0;
    }
    int sum = a[n - 1], maxi = a[n - 1];
    if (a[n - 2] < d)
    {
        cout << sum;
        return 0;
    }
    sum += a[n - 2] - d - d;
    int l = a[n - 1] - d, r = a[n - 2] - d;
    maxi = max(maxi, sum);

    for (int i = n - 3; i >= 0; i--)
    {
        if (a[i] < d || (l < d && r < d) || (l - d < d && r - d < d))
            break;
        if (l < r)
        {
            if (l - d < d)
            {
                r = a[i] - d;
                sum += a[i] - d - d;
            }
            else
            {
                l = a[i] - d;
                sum += a[i] - d - d;
            }
        }
        else
        {
            if (r - d < d)
            {
                l = a[i] - d;
                sum += a[i] - d - d;
            }
            else
            {
                r = a[i] - d;
                sum += a[i] - d - d;
            }
        }
        maxi = max(maxi, sum);
    }


    cout << maxi;
    return 0;}

/*



*/

