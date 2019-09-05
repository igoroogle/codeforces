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

int a[50010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, sum = 0;
    cin >> n;
    multiset<int> t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        t.insert(a[i]);
    }

    if (n == 1) {
        cout << sum << '\n';
        return 0;
    }

    int ans = sum;
    for (int i = 0; i < n; ++i) {
        t.erase(t.find(a[i]));
        sum -= a[i];

        for (int x = 1; x <= 100; ++x) {
            if (a[i] % x) {
                continue;
            }

            ans = min(ans, sum + a[i] / x + (*t.begin()) * (x - 1));
        }
        sum += a[i];
        t.insert(a[i]);
    }

    cout << ans << '\n';
}
