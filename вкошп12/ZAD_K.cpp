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
#define NAME "forest"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef unsigned int unt;
typedef long long ll;
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
ll a[999999], k1[10], k2[10], k3[10];
bool b[999999];
int main()
{
    //FREOPEN;
    ll i, j, n, k = 0, t, ii, kp;
    for (i = 100; i <= 999; i++)
        for (j = i + 1; j <= 999; j++)
            if ((i * j >= 100000) && (i * j <= 999999) && (!b[i * j]))
            {
                b[i * j] = 1;
                for (t = 0; t < 10; t++)
                {
                    k1[t] = 0;
                    k2[t] = 0;
                    k3[t] = 0;
                }

                ii = i;
                while (ii > 0)
                {
                    k1[ii % 10]++;
                    ii /= 10;
                }

                ii = j;
                while (ii > 0)
                {
                    k2[ii % 10]++;
                    ii /= 10;
                }

                ii = i * j;
                while (ii > 0)
                {
                    k3[ii % 10]++;
                    ii /= 10;
                }

                k++;
                kp = k;
                for (t = 0; t < 10; t++)
                    if (k1[t]  + k2[t] != k3[t])
                    {
                        k--;
                        break;
                    }

                if (kp == k)
                {
                    cout << i << ' '  << j << ' '  << i * j << endl;
                }
            }
        cout << k << endl;

}


/*





*/


