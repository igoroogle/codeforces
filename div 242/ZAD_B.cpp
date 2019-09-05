#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int val = 1000000;
pair<int, int> a[1100];
int main()
{
    int n, i, x, y, k, j, s, r;
    cin >> n >> s;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &k);
        a[i] = make_pair(x * x + y * y, k);
    }
    sort(a, a + n);
    j = 0;
    r = 0;

    while ((j < n) && (s < val))
    {
        if (a[j].first > r) r = a[j].first;
        s += a[j].second;
        j++;
    }

    if (s < val) cout << -1 << endl;
    else cout << fixed << setprecision(11) << sqrt(ld(r)) << endl;
    return 0;
}
