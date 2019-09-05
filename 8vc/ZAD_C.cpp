#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
int a[1000100], b[1000100], c[3000100];
int main()
{
    int n, m, ans = 0, i, kol = 0, j = 6, h;
    cin >> n >> m;
    for (i = 0; i < n + m + 4; i++)
    {
        c[kol++] = j;
        j += 6;
    }

    j = 2;
    for (i = 0; i < n; i++)
    {
        if (!(j % 3))
            j += 2;
        a[i] = j;
        j += 2;
    }

    j = 3;
    for (i = 0; i < m; i++)
    {
        if (!(j % 2))
            j += 3;
        b[i] = j;
        j += 3;
    }
    j = 0;
    h = max(a[n - 1], b[m - 1]);
    while ((h > c[j]) && (n + m > 0))
    {
        if ((m == 0) || ((n > 0) && (a[n - 1] > b[m - 1])))
        {
            j++;
            n--;
        }
        else
        {
            j++;
            m--;
        }
        h = c[j - 1];
        if (n > 1)
            h = max(a[n - 1], h);
        if (m > 1)
            h = max(b[m - 1], h);
    }
    cout << h << endl;
    return 0;
}
