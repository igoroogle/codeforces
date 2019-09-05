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
ll a[2010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll m = n + 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << n + 1 << '\n';
    for (int i = n - 1; i >= 0; --i) {
        int vl = a[i] % m;
        vl = (i + m - vl) % m;
        cout << 1 << ' ' << i + 1 << ' ' << vl << '\n';
        for (int j = 0; j <= i; ++j) {
            a[j] += vl;
        }
    }

    cout << 2 << ' ' << n << ' ' << m << '\n';

    /*cout << "--\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] % m << ' ';
    }*/
}
