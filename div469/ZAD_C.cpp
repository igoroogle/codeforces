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
vector<string> ans;
int main() {
    ios_base::sync_with_stdio(0);
    string s, t;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if ((t.empty()) || (t.back() == '1')) {
                t.pb('0');
            } else {
                if (int(t.size()) == 1) {
                    cout << -1 << endl;
                    return 0;
                }
                ans.pb(t);
                t.clear();
                t.pb('0');
            }
        } else {
            if ((t.empty()) || (t.back() == '1')) {
                cout << -1 << endl;
                return 0;
            }

        }
    }
}
