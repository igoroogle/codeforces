#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, i, h;
    cin >> n >> h;
    for (i = 1; i < n; ++i) {
        cout << fixed << setprecision(11) << ld(h) / ld(sqrt(ld(n) / ld(i))) << ' ';
    }
}
