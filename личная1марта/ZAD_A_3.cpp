#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100010];
int main()
{
    freopen("bumblebee.in", "r", stdin);
    freopen("bumblebee.out", "w", stdout);
    int i, n, l, r, q;
    cin >> n;
    a[0] = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == 1)
            a[i] = 0;
        else
            a[i] = 1;
        a[i] = a[i - 1] + a[i];
    }
    cin >> q;
    for (i = 0; i < q; i++)
    {
        scanf("%d%d", &l, &r);
        if (a[r] - a[l - 1])
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
