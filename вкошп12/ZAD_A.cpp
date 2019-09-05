#include "bits/stdc++.h"

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "billboard"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef unsigned int unt;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 7e18;
const ld EPS = 1e-9;
const ld PI = 3.14159265358979310000;
const ll MD = 535355424;
const ll T = 34539;
const int N = 200101;
const int M = 505;

int n, m, k, res;
ull ar[110][110], ar1[110][110];
map <pair <ull, ull>, int > q;
char ch;

int main()
{
    FREOPEN;

    cin >> k >> n >> m;

    for (int z = 0; z < k; z++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> ch;
                if (ch == '*')
                {
                    if (z < 50)
                        ar[i][j] |= (1ull << ull(z));
                    else
                        ar1[i][j] |= (1ull << ull(z - 50));
                }
            }


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (q[mp(ar[i][j], ar1[i][j])] == 0)
            {

                res++;
                q[mp(ar[i][j], ar1[i][j])] = 1;
            }

    cout << res;
    return 0;
}


/*





*/


