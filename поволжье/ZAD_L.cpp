#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1111], b[1111], c[1111];
int main()
{
    int i, j, n, s = 0, mx = 0, p = 0, g = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &c[i]);
    for (i = 0; i < n; i++)
        {
            if (abs(c[i] - b[i]) < abs(c[i] - a[i]))
                p++;
            if (abs(c[i] - b[i]) > abs(c[i] - a[i]))
                g++;
        }
    cout << g << ' ' << p << endl;
    return 0;
}
