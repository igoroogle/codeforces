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
    string s;
    cin >> s;
    s += s;
    int ans = 1, cur = 1;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] != s[i - 1]) {
            ++cur;
        } else {
            cur = 1;
        }
        ans = max(cur, ans);
    }
    ans = min(ans, int(s.length()) / 2);
    cout << ans << endl;
}
