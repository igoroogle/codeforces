#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010], b[100010];
int main()
{
    int n, mn = 0, i;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = n - 1; i >= 0; i--)
    {
        if (mn + 1 > a[i])
            b[i] = mn + 1 - a[i];
        mn = max(mn, a[i]);
    }
    for (i = 0; i < n; i++)
        printf("%d ", b[i]);
    return 0;
}
