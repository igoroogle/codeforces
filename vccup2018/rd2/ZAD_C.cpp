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
ll m[100010], add[100010];
vector<int> ads;
int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll i;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    ll s = 1;
    add[0] = 1;
    for (int i = 1; i < n; ++i) {
        ads.pb(i);
        while (m[i] >= s) {
            ++add[ads.back()];
            ++s;
            ads.pop_back();
        }
    }
    s = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        s += add[i];
        //cout << s << endl;
        ans += max(s - m[i] - ll(1), ll(0));
    }
    cout << ans << endl;
}
