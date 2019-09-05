#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int DL = 300001;
const ll INF = 100000000000000001;
int nat[DL], nat2[DL], hor[DL], a[DL], b[DL], n;
ll dp[DL], val0[DL], val1[DL], val2[DL], val3[DL], val4[DL], dp1[DL], dp2[DL], dp3[DL], v1, v2, v3, v4, v;
pair <int, int> a1[DL], b1[DL];
void change(int i);
int main()
{
    int q, i, j, s, x, y, x1 = -1, y1 = -1;
    cin >> n >> q;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a1[i].first);
        a1[i].second = i;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &b1[i].first);
        b1[i].second = i;
    }

    sort(a1, a1 + n);
    sort(b1, b1 + n);
    reverse(a1, a1 + n);
    reverse(b1, b1 + n);
    for (i = 0; i < n; i++)
    {
        nat[a1[i].second] = i;
        nat2[b1[i].second] = i;
    }
    for (i = 0; i < n; i++)
        hor[i] = nat2[a1[i].second];
    for (i = 0; i < n; i++)
    {
        a[i] = a1[i].first;
        b[i] = b1[i].first;
    }
    for (i = 0; i < n; i++)
    {
        if (i - 2 >= 0)
            val0[i] = ll(a[i]) * ll(b[i - 2]);
        if (i - 1 >= 0)
            val1[i] = ll(a[i]) * ll(b[i - 1]);
        val2[i] = ll(a[i]) * ll(b[i]);
        if (i + 1 < n)
            val3[i] = ll(a[i]) * ll(b[i + 1]);
        if (i + 2 < n)
            val4[i] = ll(a[i]) * ll(b[i + 2]);
    }
    for (i = 0; i < n; i++)
        change(i);
    while (q--)
    {
        scanf("%d%d", &x, &y);
        x = nat[x - 1];
        y = nat[y - 1];
        swap(hor[x], hor[y]);
        if (x > y)
            swap(x, y);
        for (i = x; i < min(x + 4, n); i++)
            change(i);
        for (i = y; i < min(y + 4, n); i++)
            change(i);
        dp[0] = 0;
        dp[1] = dp1[0];
        dp[2] = max(-INF, max(dp2[1], dp1[1] + dp[1]));
        for (i = 2; i < n; i++)
           dp[i + 1] = max(dp[i] + dp1[i], max(dp[i - 1] + dp2[i], dp[i - 2] + dp3[i]));
        printf("%I64d\n", dp[n]);
    }
    return 0;
}

void change(int i)
{
    v1 = v2 = v3 = v4 = v = -INF;
    if (hor[i] != i)
        v = val2[i];
    if ((i - 1 >= 0) && (hor[i - 1] != i) && (hor[i] != i - 1))
        v1 = val1[i] + val3[i - 1];
    if (i - 2 >= 0)
    {
        if ((hor[i - 2] != i) && (hor[i - 1] != i - 2) && (hor[i] != i - 1))
            v2 = val4[i - 2] + val1[i - 1] + val1[i];
        if ((hor[i - 2] != i) && (hor[i - 1] != i - 1) && (hor[i] != i - 2))
            v3 = val4[i - 2] + val2[i - 1] + val0[i];
        if ((hor[i - 2] != i - 1) && (hor[i - 1] != i) && (hor[i] != i - 2))
            v4 = val3[i - 2] + val3[i - 1] + val0[i];
    }
    dp1[i] = v;
    dp2[i] = v1;
    dp3[i] = max(v2, max(v3, v4));
}
