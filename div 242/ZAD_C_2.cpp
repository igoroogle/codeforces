#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int pw[1000100];
int main()
{
    int n, i, j, p, ans = 0, x;
    cin >> n;
    pw[0] = 0;
    for (i = 1; i <= n; i++) pw[i] = i ^ pw[i - 1];
    for (i = 1; i <= n; i++)
    {
        if ((n / i) % 2) ans ^= pw[i - 1];
        ans ^= pw[n % i];
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        ans ^= x;
    }
    cout << ans << endl;
}
