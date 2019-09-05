#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int a[107];
int main()
{
    int n, i, d, ans = 0;
    cin >> n >> d;
    d--;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (a[d] == 1)
        ans++;

    for (i = 1; i <= 103; i++)
    {
        if ((d - i < 0) && (d + i >= n))
            break;
        if (d - i < 0)
        {
            ans += a[d + i];
            continue;
        }

        if (d + i >= n)
        {
            ans += a[d - i];
            continue;
        }

        if (a[d - i] == a[d + i])
            ans += a[d - i] + a[d + i];
    }

    cout << ans << endl;
    return 0;
}
