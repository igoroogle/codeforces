#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ll n, a, b, x, y, v, sq;
    ld mn = 2E18;
    cin >> a >> b >> n;
    while (n--)
    {
        scanf("%I64d%I64d%I64d", &x, &y, &v);
        sq = (x - a) * (x - a) + (y - b) * (y - b);
        mn = min(mn, ld(sqrt(ld(sq))) / ld(v));
    }

    cout << fixed << setprecision(11) << mn << endl;
    return 0;
}
