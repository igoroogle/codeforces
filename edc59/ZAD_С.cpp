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

ll ar[200010];
string s;

ll get_ans(vector<ll>& a, int k) {
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < min(int(a.size()), k); ++i) {
        ans += a[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    cin >> s;

    ll vans = 0;
    vector<ll> a;
    a.pb(ar[0]);

    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            vans += get_ans(a, k);
            a.clear();
        }
        a.pb(ar[i]);
    }

    vans += get_ans(a, k);
    cout << vans << '\n';
}
