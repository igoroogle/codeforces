#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1E9;
int ans[100010], ans2[100010];
string s, t;
int main() {
    ios_base::sync_with_stdio(0);
    int n, i, j, mn = INF;
    cin >> n >> s;
    for (i = 0; i < s.length(); ++i) {
        ans[i] = s.length() - i - 1;
    }

    int f, val;
    for (i = 1; i < n; ++i) {
        cin >> t;
        f = 0;
        for (j = 0; j < t.length(); ++j) {
            if (f == 0) {
                if ((j > s.length()) || (s[j] < t[j])) {
                    f = 1;
                } else if (s[j] > t[j]) {
                    val = ans[j - 1];
                    f = 2;
                }
            }

            if (f == 1) {
                ans2[j] = min(ans[int(s.length()) - 1] + int(t.length()) - j - 1, INF);
                continue;
            } else if (f == 2) {
                ans2[j] = min(val + int(t.length()) - j - 1, INF);
                continue;
            }

            ans[j] = min(ans2[j] + int(t.length()) - j - 1, INF);
        }

        for (j = 0; j < t.length(); ++j) {
            ans[j] = ans2[j];
        }
        s = t;
    }

    for (i = 0; i < s.length(); ++i) {
        mn = min(mn, ans[i]);
    }

    cout << mn << endl;
}
