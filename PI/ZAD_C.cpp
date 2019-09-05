#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
map <ll, ll> v, u;
ll a[200010];
int main()
{
    ll n, k, i, ans = 0, x, y,f, l;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (i = 0; i < n; i++)
    {
        if (a[i] % k == 0)
        {
            x = a[i] / k;
            ans += u[x];
            u[a[i]] += v[x];
        }
        v[a[i]]++;
    }
    cout << ans << endl;
    return 0;
}
