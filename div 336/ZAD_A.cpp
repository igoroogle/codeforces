#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
pair<ll, ll> a[110];
int main()
{
    ll n, i, f, t, tim = 0, s;
    cin >> n >> s;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &f, &t);
        a[i] = mp(f, t);
    }

    sort(a, a + n);
    reverse(a, a + n);
    for (i = 0; i < n; i++)
    {
        while (s > a[i].x)
        {
            s--;
            tim++;
        }

        tim = max(tim, a[i].y);
    }

    cout << tim + s << endl;
    return 0;
}
