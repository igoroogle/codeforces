#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    multiset<int> t;
    int x, pr;
    cin >> pr;
    ll ans = n;
    int kl = n;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        t.insert(x - pr - 1);
        pr = x;
    }

    while (kl > k) {
        ans += ll(*t.begin());
        t.erase(t.begin());
        --kl;
    }

    cout << ans << '\n';
}
