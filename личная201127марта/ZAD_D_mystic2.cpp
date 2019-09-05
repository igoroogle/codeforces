#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000100;
ll fib[110], ans[10010];
int main()
{
    freopen("grasshopper.in", "r", stdin);
    freopen("grasshopper.out", "w", stdout);
    ll i, j, cnt = 0, n, k, vl, kol = 0;
    fib[1] = 1;
    fib[2] = 1;
    cnt = 2;
    while (fib[cnt - 1] + fib[cnt] < INF)
    {
        cnt++;
        fib[cnt] = fib[cnt - 1] + fib[cnt - 2];
    }
    //cout << cnt << endl;
    cin >> n >> k;
    if ((k == 0) && (n < 3))
    {
        cout << "Impossible\n";
        return 0;
    }

    if (k == 0)
    {
        printf("1 ");
        for (i = 2; i < n; i++)
            printf("0 ");
        printf("1 ");
        return 0;
    }
    if ((n == 2) && (k == 1))
    {
        printf("1 1");
        return 0;
    }

    if (n == 2)
    {
        cout << "Impossible\n";
        return 0;
    }
    vl = k;
    for (i = cnt; i >= 3; i--)
    {
        if (vl < 2)
            break;
        while (((i + 1 + kol <= n) || ((kol == 0) && (i <= n))) && (vl % fib[i] == 0))
        {
            vl /= fib[i];
            if (kol > 0)
            {
                ans[kol] = 0;
                kol++;
            }

            for (j = 0; j < i; j++)
            {
                ans[kol] = 1;
                kol++;
            }
        }
    }

    if (kol == 0)
    {
        ans[0] = 1;
        kol++;
    }

    if ((vl > 1) || (n - kol == 1))
    {
        cout << "Impossible\n";
        return 0;
    }

    for (i = kol; i + 1 < n; i += 2)
    {
        ans[kol] = 0;
        ans[kol + 1] = 1;
        kol += 2;
    }
    if (kol < n)
    {
        ans[kol] = 1;
        kol++;
    }

    for (i = 0; i < kol; i++)
        printf("%I64d ", ans[i]);
}
