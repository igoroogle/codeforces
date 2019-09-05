#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ll n, sum = 0;
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (ll i = 1; i <= min(n, (ll)30000000); i++)
    {
        sum = max(sum, i * (n - i));
    }
    cout << sum;
    return 0;
}
