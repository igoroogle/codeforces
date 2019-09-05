#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
pair<int, int> val[100010];
int ans[100010];
int main()
{
    int n, i, j, mx = 0, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        mx = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &x);
            mx = max(mx, x);
        }
        val[i] = mp(mx, i);
    }

    sort(val, val + n);
    for (i = 0; i < n; i++)
        ans[val[i].y] = i + 1;
    for (i = 0; i < n; i++)
        printf("%d ", ans[i]);
    return 0;
}
