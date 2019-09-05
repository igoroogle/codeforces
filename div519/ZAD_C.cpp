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

int main() {
    ios_base::sync_with_stdio(0);
    char mn = char('z' + 1);
    string s;
    cin >> s;
    vector<int> ans;
    ans.reserve(s.length() + 1);
    ans.pb(0);
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] <= mn) {
            ans.back() = 1 - ans.back();
            ans.pb(1);
            mn = s[i];
        } else {
            ans.pb(0);
        }
    }

    for (size_t i = 1; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
}
