#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef long double ld;
using namespace std;
string s, rs, ms;
unordered_map<string, int> t;
vector<ll> a[100010], b[100010];
vector<ll> c[100010];
int main() {
    ios_base::sync_with_stdio(0);
    int k, n, kl1 = 0, kl2 = 0, i, ind, j;
    ll cr;
    cin >> k >> n;
    for (i = 0; i < k; ++i) {
        cin >> s >> cr;
        rs = s;
        reverse(rs.begin(), rs.end());
        if (s == rs) {
            if (t[s] == 0) {
                ++kl2;
                t[s] = kl2;
                ind = kl2;
            } else {
                ind = t[s];
            }

            c[ind].pb(cr);
            continue;
        }

        ms = min(s, rs);
        if (t[ms] == 0) {
                ++kl1;
                t[ms] = kl1;
                ind = kl1;
            } else {
                ind = t[ms];
            }

        if (ms == s) {
            a[ind].pb(cr);
        } else {
            b[ind].pb(cr);
        }
    }

    ll ans = 0, to_ans = 0;
    for (i = 1; i <= kl1; ++i) {
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
        reverse(b[i].begin(), b[i].end());
        for (j = 0; j < min(a[i].size(), b[i].size()); ++j) {
            if (a[i][j] + b[i][j] <= 0) {
                break;
            }

            ans += a[i][j] + b[i][j];
        }

    }

    for (i = 1; i <= kl2; ++i) {
        sort(c[i].begin(), c[i].end());
        reverse(c[i].begin(), c[i].end());
        for (j = 1; j < c[i].size(); j += 2) {
            if (c[i][j - 1] + c[i][j] <= 0) {
                to_ans = max(to_ans, c[i][j - 1]);
                break;
            }

            ans += c[i][j - 1] + c[i][j];
            to_ans = max(to_ans, -c[i][j]);
        }

        if (c[i].size() % 2) {
            to_ans = max(to_ans, c[i][c[i].size() - 1]);
        }
    }


    ans += to_ans;
    cout << ans << endl;
}
