#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ll n;
    cin >> n;
    cout << ll(n / ll(2)) * ll(n - n / ll(2));
    //cout << n / 2 * (n - n / 2) << endl;
}
