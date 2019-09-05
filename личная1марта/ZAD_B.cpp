#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010];
set<ll> b;
int main()
{
    //freopen("bumblebee.in", "r", stdin);
    //freopen("bumblebee.out", "w", stdout);
    ll n, i;
    //cin >> n;
    b.insert(0);
    b.insert(7);
    b.insert(35);
    b.insert(100);
    cout << *b.lower_bound(100) << endl;
    return 0;
}
