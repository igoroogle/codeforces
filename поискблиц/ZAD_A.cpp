#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int rig[100010], lef[100010], a[100010];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, i, mn;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (a[0] >= 0)
        lef[0] = 1;

    for (i = 1; i < n; i++)
        {
            lef[i] = lef[i - 1];
            if (a[i] >= 0)
                lef[i]++;
        }

    for (i = n - 1; i >= 0; i--)
        {
            rig[i] = rig[i + 1];
            if (a[i] <= 0)
                rig[i]++;
        }

    mn = n;
    for (i = 0; i < n - 1; i++)
        mn = min(lef[i] + rig[i + 1], mn);
    cout << mn << endl;
    return 0;
}
