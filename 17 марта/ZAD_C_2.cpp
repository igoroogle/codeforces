#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
    freopen("kaboom.in", "r", stdin);
    freopen("kaboom.out", "w", stdout);
    ll a, b, c, x, y, ans;
    cin >> a >> b >> c;
    cout << a + (a - a / c) * b << endl;
    return 0;
}
