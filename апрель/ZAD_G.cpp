#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a[2555];
int main() {
    ll f = 1, val = 0, ans = 0, kl = 0;
    cin >> s;
    s += "-";
    for (ll i = 0; i < s.length(); ++i) {
        if ((s[i] != '+') && (s[i] != '-')) {
            val = val * ll(10) + ll(s[i] - '0');
        } else {
            if (f) {
                ans += val;
            } else {
                ans -= val;
            }
            f = (s[i] == '+');
            val = 0;
        }
    }


    if (ans == 0) {
        ++kl;
    }

    while (ans > 0) {
        a[kl++] = ans % 10;
        ans /= 10;
    }

    reverse(a, a + kl);
    for (ll i = 0; i < kl; ++i) {
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++\n";
        ans = a[i];
        while (ans--) {
            cout << '+';
        }
        cout << ".>\n";
    }
}
