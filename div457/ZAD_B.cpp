#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll DL = 100010;
const ll DL2 = 200030;
bool happy(int x) {
    return (((x / 10 == 7) || (x % 10 == 7)));
}

ll a[DL2];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, k, bt = 0, mn = 64, j;
    cin >> n >> k;
    for (ll i = 60; i >= 0; --i) {
        if ((ll(1) << i) & n) {
            ++a[i + DL];
            ++bt;
            mn = i;
        }
    }

    if (bt > k) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";

    int i = 60;
    while (bt < k) {
        if (a[i + DL] == 0) {
            --i;
            continue;
        }
        a[i - 1 + DL] += 2;
        --a[i + DL];
        ++bt;
    }

    for (int i = DL2 - 1; i >= 0; --i) {
        for (int j = 0; j < a[i]; ++j) {
            cout << i - DL << ' ';
        }
    }
}
