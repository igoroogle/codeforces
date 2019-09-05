#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 100010;
int a[1111], b[DL], c[DL];
int main()
{
    int i, j, n, m, s = 0, mx = 0, ost = 0, x;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    j = 1;
    for (i = 1; i < DL; i++)
    {
        if (j <= n)
            ost += m;
        while (j <= n)
        {
            if (a[j] > ost)
                break;
            ost -= a[j];
            j++;
        }
        b[i] = j - 1;
        c[i] = ost;

    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &x);
        printf("%d %d\n", b[x], c[x]);
    }
    return 0;
}
