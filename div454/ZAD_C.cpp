#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool a[27], b[27];
int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 27; ++i) {
        a[i] = true;
    }
    int n;
    cin >> n;
    int ans = 0;
    char c;
    string s;
    --n;
    int cn;
    while (n--) {
        /*for (int i = 0; i < 26; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;*/
        cin >> c >> s;
        if (c == '.') {
            for (int i = 0; i < s.length(); ++i) {
                a[s[i] - 'a'] = false;
            }
            continue;
        }

        cn = 0;
        for (int i = 0; i < 26; ++i) {
            if (a[i]) {
                ++cn;
            }
        }

        if (cn == 1) {
            ++ans;
        }

        if (c == '?') {
            a[s[0] - 'a'] = false;
        } else {
            for (int i = 0; i < 26; ++i) {
                b[i] = false;
            }

            for (int i = 0; i < s.length(); ++i) {
                b[s[i] - 'a'] = true;
            }

            for (int i = 0; i < 26; ++i) {
                a[i] = b[i] && a[i];
            }
        }
    }

    cout << ans << endl;

}
