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
int a[20][20], b[20][20];
int main()
{
    cout << 2015 << endl;
    srand(time(0));
    int x1 = 1, y1 = 1, x2 = 1, y2 = 2;
    cout << x1 << ' ' << y1 << x2 << ' ' << y2 << endl;
    for (int i = 1; i < 2015; i++)
        printf("%d %d %d %d\n", rand() % 500 + 1, 1, rand() % 500 + 501, 2);
    return 0;
}
