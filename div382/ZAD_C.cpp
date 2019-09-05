#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll a[100010];
int main() {
    ll n, st = 0, v = 1;
    cin >> n;
    while (v < n) {
        v <<= ll(1);
        ++st;
    }

    cout << st << endl;
    return 0;
}
