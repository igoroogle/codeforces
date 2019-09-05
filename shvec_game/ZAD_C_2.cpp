#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[110], a[110];
int main()
{
    ll i, j, k, n, m, kl = 0, s1 = 0, s2 = 0, md;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> m;
        for (j = 0; j < m; j++)
            scanf("%d", &t[j]);
        for (j = 0; j < m / 2; j++)
            s1 += t[j];

        if (m % 2)
        {
            md = m / 2;
            a[kl++] = t[md];
            md++;
        }

        else
            md = m / 2;
        for (j = md; j < m; j++)
            s2 += t[j];
    }

    if (kl > 0)
    {
        sort(a, a + kl);
        reverse(a, a + kl);
    }

    for (i = 0; i < kl; i++)
    {
        if (i % 2)
            s2 += a[i];
        else
            s1 += a[i];
    }

    cout << s1 << ' ' << s2 << endl;
    return 0;
}
