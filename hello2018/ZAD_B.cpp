#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[1010], p[1010];
bool b[1010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, i;
    cin >> n;
    for (ll i = 2; i <= n; ++i) {
        cin >> p[i];
        if (!b[i]) {
            ++a[p[i]];
        }

        if (!b[p[i]]) {
            b[p[i]] = true;
            if (p[p[i]] > 0) {
                --a[p[p[i]]];
            }
        }
    }


    for (ll i = 1; i <= n; ++i) {
        if ((b[i]) && (a[i] < 3)) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}
