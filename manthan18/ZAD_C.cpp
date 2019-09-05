#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    string a, b;
    int n;
    ll ans = 0;
    cin >> n;
    cin >> a >> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if ((i + 1 < n) && (a[i + 1] != b[i + 1]) && (a[i + 1] != a[i])) {
                swap(a[i], a[i + 1]);
            }
            ++ans;
        }
    }

    cout << ans << endl;
}
