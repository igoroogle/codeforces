#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(a) ((a) * (a))
#define forn(i, n) for(int i = 0; i < int(n); i++)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const
    int MOD = 1000000007;
    int INF = 200000;
    long long INF64 = 500000;
    long double EPS = 0.2;
    long double PI = 3.14159265358979310000;
    ll MD = 1000000007;//184756
    const int N = 55;

string s[N], ss;
int n, m, k;

bool prov()
{
    forn(i, n)
    {
        forn(j, m - sz(ss) + 1)
        {
            int z = 0;
            while (z < sz(ss) && s[i][j + z] == ss[z])
            {
                z++;
            }
            if (z == sz(ss))
                return 1;
        }
    }

    for (int i = 0; i <= n - sz(ss); i++)
    {
        forn (j, m)
        {
            int  z = 0;
            while (z < sz(ss) && s[i + z][j] == ss[z])
            {
                z++;
            }
            if (z == sz(ss))
                return 1;
        }
    }
    return 0;

}


int main()
{
    freopen("words.in", "r", stdin);
    freopen("words.out", "w", stdout);

    cin >> n >> m;
    forn(i, n)
        cin >> s[i];
    cin >> k;
    forn(i, k)
    {
        cin >> ss;
        if (prov())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
