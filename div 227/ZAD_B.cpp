#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[3010], b[3010];
int main()
{
    int i, j, n, m, l = 0, ans = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + m);
    for (i = 0; i < n; i++)
    {
        while ((l < m) && (b[l] < a[i]))
            l++;
        if (l < m)
            l++;
        else
            ans++;
    }
    cout << ans << endl;
    return 0;
}
