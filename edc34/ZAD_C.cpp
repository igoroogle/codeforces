#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[5003];
bool b[5003];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    while (n > 0) {
        ++ans;
        b[0] = true;
        for (int i = 1; i < n; ++i) {
            b[i] = (a[i] < a[i - 1]);
        }
        m = 0;
        for (int i = 1; i < n; ++i) {
            if (!b[i]) {
                a[m++] = a[i];
            }
        }
        n = m;
    }
    cout << ans << endl;
}
