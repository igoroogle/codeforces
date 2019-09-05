#include <cstdlib>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
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

const int MOD = 1e9 + 7;
const long long INF64 = 9e18;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const int N = 100001;
const int M = 12001;
const ll INF = 1000000000000000;
ll n, s, t, a[110], l, r, m, k, u, u1, i;
int main()
{
    //freopen("tickets.in", "r", stdin);
    //freopen("tickets.out", "w", stdout);
    cin >> n >> s >> t;
    cin >> l >> r;
    cin >> m;
    bool f1 = 0, f2 = 0;
    for (i = 0; i < m; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + m);
    k = 1;
    for (i = 1; i < m; i++)
        if (a[i] != a[i - 1])
        {
            k++;
            a[k - 1] = a[i];
        }
    m = k;
    for (i = 0; i < m; i++)
    {
        if (a[i] == s)
            f1 = 1;
        if (a[i] == t)
            f2 = 1;
    }
    if ((f1) && (f2))
    {
        cout << "add " << s << ' ' << t << ' ' << l << endl;
        fflush(stdout);
        scanf("%I64d", &u);
        if (u == l)
            cout << "answer ok\n";
        else
            cout << "answer impossible\n";
        fflush(stdout);
        return 0;
    }
    for (i = 0; i < m - 1; i++)
    {
        printf("add %I64d %I64d %I64d\n", a[i], a[i + 1], ll(0));
        fflush(stdout);
        scanf("%I64d", &u);
        if ((u >= l) && (u <= r))
        {
            cout << "answer ok\n";
            fflush(stdout);
            return 0;
        }
    }
    for (i = 0; i < m - 1; i++)
    {
        u1 = u;
        printf("delete %I64d %I64d %I64d\n", a[i], a[i + 1], ll(0));
        fflush(stdout);
        scanf("%I64d", &u);
        if ((u >= l) && (u <= r))
        {
            cout << "answer ok\n";
            fflush(stdout);
            return 0;
        }
        if (u1 <= l)
        {
            printf("add %I64d %I64d %I64d\n", a[i], a[i + 1], l - u1);
            fflush(stdout);
            scanf("%I64d", &u);
            if ((u >= l) && (u <= r))
            {
                cout << "answer ok\n";
                fflush(stdout);
                return 0;
            }
            printf("delete %I64d %I64d %I64d\n", a[i], a[i + 1], l -  u1);
            fflush(stdout);
            scanf("%I64d", &u);
            if ((u >= l) && (u <= r))
            {
                cout << "answer ok\n";
                fflush(stdout);
                return 0;
            }
        }
    }
    cout << "answer impossible\n";
    fflush(stdout);
    return 0;
}
