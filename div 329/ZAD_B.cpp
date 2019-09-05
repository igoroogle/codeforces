#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
pair <pair<ll, ll> , ll> a[100010], a1[100010];
int main()
{
    ll n, i, x1, x2, k, b, x;
    cin >> n >> x1 >> x2;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &k, &b);
        a[i] = mp(mp(k * x1 + b, k * x2 + b), i);
        a1[i] = mp(mp(k * x2 + b, k * x1 + b), i);
    }

    sort(a, a + n);
    sort(a1, a1 + n);

    for (i = 0; i < n; i++)
        if (a[i].y != a1[i].y)
        {
            cout << "YES\n";
            return 0;
        }

    for (i = 1; i < n; i++)
        if (a[i].x == a[i - 1].x)
        {
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}
