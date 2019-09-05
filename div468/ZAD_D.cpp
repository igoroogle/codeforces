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
int sm[100010], a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    int n, p;
    cin >> n;
    sm[0] = 0;
    a[0] = 1;
    for (int i = 1; i < n; ++i) {
        cin >> p;
        --p;
        sm[i] = sm[p] + 1;
        a[sm[i]] ^= 1;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
