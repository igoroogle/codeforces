#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MX = 2000000001;
int main()
{
    ll l, r, k, n = 1, kol = 0, ans = 1;
    bool f = 1;
    cin >> l >> r >> k;

    if ((n >= l) && (n <= r))
            {
                printf("%I64d ", n);
                f = 0;
            }

    while ((ll(sqrt(ld(n))) * ll(sqrt(ld(k))) <= MX) && (n * k <= r))
    {
        n *= k;
        if ((n >= l) && (n <= r))
            {
                printf("%I64d ", n);
                f = 0;
            }
    }

    if (f)
        cout << -1 << endl;
    return 0;
}
