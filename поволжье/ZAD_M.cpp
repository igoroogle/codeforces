#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[11], b[11], c[11];
int main()
{
    int i, j, n, s = 0, mx = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &c[i]);
    for (i = 0; i < n; i++)
        mx = max(mx, (a[i] - 1) / b[i] + 1);
    for (i = 0; i < n; i++)
        s += (b[i] * mx - a[i]) * c[i];
    cout << s << endl;
    return 0;
}
