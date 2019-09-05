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
    vector<ll> a = {1, 2, 3, 4, 5};
    vector<ll> ans;
    do {
        for (auto cur : a) {
            ans.pb(cur);
        }
    } while (next_permutation(a.begin(), a.end()));

    /*for (auto cur : ans) {
        cout << cur << ' ';
    }*/

    ll vans = 0;
    ll hans = 0;
    for (int i = 0; i < ans.size() - a.size() + 1; ++i) {
        ll sm = 0;
        for (int j = i; j < i + a.size(); ++j) {
            sm += ans[j];
        }

        if (sm == ll(a.size()) * ll(a.size() + 1) / ll(2)) {
            ++vans;
            if (i % int(a.size()) == 0) {
                continue;
            }
            cout << i << ' ';
        } else {
            ++hans;
        }
    }

    cout << endl;

    cout << vans << endl;
    cout << hans << endl;
}
