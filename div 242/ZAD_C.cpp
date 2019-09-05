#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    int n, i, j, p,ans = 0;
    cin >> n;
    for (p = 1; p <=n; p++)
        {
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    ans ^= i % j;
            cout << p << ' ' << ans << endl;
        }


    return 0;
}
