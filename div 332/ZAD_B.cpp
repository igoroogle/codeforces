#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int main()
{
    int n, m, f = 1, i, x;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (b[x] == 0)
            b[x] = i;
        else
            b[x] = -1;
    }

    for (i = 0; i < m; i++)
    {
        scanf("%d", &x);
        if (b[x] == 0)
        {
            f = 0;
            break;
        }

        if (b[x] == -1)
        {
            f = -1;
            continue;
        }

        a[i] = b[x];
    }

    if (f == 1)
    {
        cout << "Possible\n";
        for (i = 0; i < m; i++)
            printf("%d ", a[i]);
    }
    else if (f == 0)
        cout << "Impossible\n";
    else
        cout << "Ambiguity\n";
    return 0;
}
