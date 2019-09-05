#include<bits/stdc++.h>
#define x firsr
#define y second
#define mp make pair
#define pb push_back
using namespace std;
typedef long long ll;
bool st[100010], sr[100010];
int main()
{
    ll n, m, ssr = 0, sst = 0, ans, x, y;
    cin >> n >> m;
    ans = n * n;
    while (m--)
    {
        scanf("%I64d%I64d", &x, &y);
        x--;
        y--;
        if (!st[x])
        {
            st[x] = 1;
            ans -= (n - ssr);
            sst++;
        }

        if (!sr[y])
        {
            sr[y] = 1;
            ans -= (n - sst);
            ssr++;
        }

        printf("%I64d ", ans);
    }
    return 0;
}
