#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010];
int main()
{
    int i, n, mx = 1, d = 1;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n] = -1;
    for (i = 1; i <= n; i++)
    {
        if (a[i] < a[i - 1])
        {
            mx = max(d, mx);
            d = 1;
        }
        else d++;
    }
    cout << mx << endl;
    return 0;
}
