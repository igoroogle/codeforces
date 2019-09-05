#include<bits/stdc++.h>
using namespace std;
string a[1003], ans[1003], s;
int main() {
    ios_base::sync_with_stdio(0);
    int n, k, i, j, kl = 0, an = 0;
    for (i = 0; i < 26; ++i) {
        for (j = 0; j < 26; ++j) {
            a[kl] = "  ";
            a[kl][0] = char('A' + i);
            a[kl][1] = char('a' + j);
            ++kl;
        }
    }


    cin >> n >> k;
    for (i = 0; i < k - 1; ++i) {
        ans[i] = a[an];
        ++an;
    }

    for (i = k - 1; i < n; ++i) {
        cin >> s;
        if (s[0] == 'Y') {
            ans[i] = a[an];
            ++an;
        } else {
            ans[i] = ans[i - k + 1];
        }
    }

    for (i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}
