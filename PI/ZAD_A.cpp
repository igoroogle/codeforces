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
ll a[100010];
int main()
{
    ll n, i, x, y;
    cin >> n;
    for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
    for (i = 0; i < n; i++)
    {
        x = INF;
        if (i - 1 >= 0) x = abs(a[i - 1] - a[i]);
        y = INF;
        if (i + 1 < n) y = abs(a[i + 1] - a[i]);
        printf("%I64d %I64d\n", min(x, y), max(abs(a[0] - a[i]), abs(a[n - 1] - a[i])));
    }
    return 0;
}
