#include<bits/stdc++.h>
#define y first
#define x second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int a[300010], b[300010], c[300010], d[300010];
int main()
{
    int n, q, kl = 0, ans = 0, t, x, l = 0;
    cin >> n >> q;
    while (q--)
    {
        scanf("%d%d", &t, &x);
        if (t == 1)
        {
            a[x]++;
            c[kl++] = x;
            d[kl - 1] = a[x];
            ans++;
        }
        else if (t == 2)
        {
            ans -= a[x] - b[x];
            a[x] = b[x];
        }
        else
        {
            while (l < x)
            {
                if (b[c[l]] < d[l])
                {
                    b[c[l]]++;
                    ans--;
                }
                l++;
            }

        }

        printf("%d\n", ans);

    }


    return 0;
}
