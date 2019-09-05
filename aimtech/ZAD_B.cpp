#include <bits/stdc++.h>
#define make_pair mp
#define push_back pb
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[100010];
int main()
{
    ll n, i, ans = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);
    ans = a[0];
    for (i = 1; i < n; i++)
    {
        while (a[i] >= a[i - 1])
            a[i]--;
        if (a[i] > 0)
            ans += a[i];
    }

    cout << ans << endl;
    return 0;
}
