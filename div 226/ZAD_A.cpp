#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[110];
int main()
{
    int n, i, mx = 0, c;
    cin >> n >> c;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n - 1; i++)
        if (a[i] >= a[i + 1] + c)
            mx = max(mx, a[i] - (a[i + 1] + c));
    cout << mx << endl;
    return 0;
}
