#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("a-heap.in", "r", stdin);
    freopen("a-heap.out", "w", stdout);
    int t, n, k;
    cin >> t;
    while (t--)
    {
        scanf("%d%d", &n, &k);
        if (n == 1)
            printf("0\n");
        else if (k >= n - 1)
            printf("%d\n", n - 1);
        else
            printf("%d\n", (n - 1) % (k + 1));
    }

    return 0;
}
