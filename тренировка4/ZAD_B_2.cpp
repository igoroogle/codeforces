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

const ll MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 9e18;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const ll MD = 1248742437;
const ll T = 378531;
const int N = 200001;
const int M = 100000;


int d[N], a[N];

int main()
{
    //freopen("stock.in", "r", stdin);
    //freopen("stock.out", "w", stdout);
    int n;
    cin >> n;
    char ch;
    forn(i, n)
        if (i < n - 1)
            cout << "+ ";
        else
            cout << "+" << endl;
    fflush(stdout);
    cin >> d[0];
    int z = 0;
    for (int i = 1; i < n; i++)
    {
        forn(j, n)
        {
            if (j == i)
                ch = '+';
            else
                ch = '-';
            if (j < n - 1)
                cout << ch << " ";
            else
                cout << ch << endl;
        }
        fflush(stdout);
        cin >> d[i];
        a[i] = (d[i] + d[0]) / 2;
        z += d[i];
    }
    a[0] = -(z + (d[0] * (n - 3))) / 2;
    cout << "answer: ";
    forn(i, n)
        cout << a[i] << ' ';
    fflush(stdout);
    return 0;
}






