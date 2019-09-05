#include <bits/stdc++.h>
using namespace std;
const int DL = 10001;
int a[DL], x;

bool rec(int n)
{
   if (a[n] > -1)
        return bool(a[n]);
   int i, m = ((n + 1) >> 1), ans = 0, z;

   for (i = 1; i < m; i++)
        {
            z = (i == 1) && (n - i == 1);
            ans += !(rec(i) ^ rec(n - i) ^ z);
        }

   a[n] = ans;
   return bool(a[n]);
}

int main()
{
    freopen("divide-heaps.in", "r", stdin);
    freopen("divide-heaps.out", "w", stdout);
    int t, n, k, i;
    for (i = 0; i < DL; i++)
        a[i] = -1;
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    rec(DL - 1);
    cin >> t;
    while(t--)
    {
        scanf("%d", &x);
        printf("%d\n", a[x]);
    }

    return 0;
}
