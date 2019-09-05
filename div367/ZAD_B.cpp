#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010];
int main()
{
    int n, i, q, l, r, m, s;
    cin >> n;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    a[0] = 0;
    a[n + 1] = 1E18;
    cin >> q;
    while (q--)
    {
        scanf("%d", &s);
        l = 0;
        r = n + 1;
        while (l < r)
        {
            m = (l + r) >> 1;
            if (a[m] <= s)
                l = m + 1;
            else
                r = m;
        }

        printf("%d\n", l - 1);
    }
    return 0;
}
