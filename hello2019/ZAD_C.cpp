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
const int LEN = 500010;
int pos[LEN], neg[LEN];

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int bal = 0, min_bal = 0;
        for (auto cur : s) {
            if (cur == '(') {
                ++bal;
            } else {
                --bal;
            }
            min_bal = min(min_bal, bal);
        }
        if (bal >= 0) {
            if (min_bal < 0) {
                continue;
            }
            ++pos[bal];
        } else {
            if (min_bal != bal) {
                continue;
            }

            ++neg[-bal];
        }
    }

    int ans = pos[0] / 2;
    for (int i = 1; i < LEN; ++i) {
        ans += min(neg[i], pos[i]);
    }

    cout << ans << '\n';
    return 0;
}
