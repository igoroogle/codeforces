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
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0, l, r;
    for (int i = 0; i < n; ++i) {
        l = 0;
        r = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == '(') {
                    ++l;
                    ++r;
            } else if (s[j] == ')') {
                --l;
                --r;
            } else {
                --l;
                ++r;
            }
            l = max(0, l);
            if (r < 0) {
                break;
            }
            if (l == 0) {
                if ((j - i + 1) % 2) {
                    continue;
                }
                ++ans;
                //cout << i << ' ' << j << endl;
            }
        }
    }
    cout << ans << endl;
}
