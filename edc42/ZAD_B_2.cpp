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
    int n, a, b, as, bs, ans = 0;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s = "*" + s;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '*') {
            continue;
        }

        if (((a > b) && (s[i - 1] != 'a')) || ((a > 0) && (s[i - 1] == 'b'))) {
            s[i] = 'a';
            --a;
            ++ans;
            continue;
        } else if ((b > 0) && (s[i - 1] != 'b')) {
            s[i] = 'b';
            --b;
            ++ans;
            continue;
        }
    }

    cout << ans << endl;
}
