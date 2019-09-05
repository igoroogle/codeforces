#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull dp[11][100010];
int n, k;
int update(int p, int x, ull d);
ull get(int p, int x);
int main()
{
    int i, j, x;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        for (j = k; j > 0; j--)
            update(j, x, get(j - 1, x - 1));
        update(0, x, ull(1));
    }

    cout << get(k, n) << endl;
    return 0;
}

int update(int p, int x, ull d)
{
    int i = d;
    while (i <= n)
    {
        dp[p][i] += d;
        i = (i + 1) | i;
    }
}

ull get(int p, int x)
{
    int i = x;
    ull s = 0;
    while (i >= 0)
    {
        s += dp[p][i];
        i = ((i + 1) & i) - 1;
    }
    return s;
}
