#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long double ld;

int main()
{
    freopen("josephus.in", "r", stdin);
    freopen("josephus.out", "w", stdout);
    int n, ans = 1;
    cin >> n;
    while (ans * 2 <= n)
        ans *= 2;
    cout << 2 * (n - ans) + 1 << endl;
    return 0;
}
