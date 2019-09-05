#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef long double ld;
using namespace std;
int x[200010], y[200010];
char s[200010];
int main() {
    int n, i, ans = 1, ind = 0, kl = 1;
    cin >> n;
    scanf("%s", &s);
    for (i = 0; i < n; ++i) {
        ++kl;
        if (s[i] == 'L') {
            x[kl - 1] = x[kl - 2] + 1;
            y[kl - 1] = y[kl - 2];
        } else if (s[i] == 'R') {
            x[kl - 1] = x[kl - 2] - 1;
            y[kl - 1] = y[kl - 2];
        } else if (s[i] == 'U') {
            x[kl - 1] = x[kl - 2];
            y[kl - 1] = y[kl - 2] + 1;
        } else if (s[i] == 'D') {
            x[kl - 1] = x[kl - 2];
            y[kl - 1] = y[kl - 2] - 1;
        }

        if (abs(x[kl - 1] - x[ind]) + abs(y[kl - 1] - y[ind]) == kl - 1 - ind) {
            continue;
        }

        ++ans;
        ind = kl - 2;

        if (abs(x[kl - 1] - x[ind]) + abs(y[kl - 1] - y[ind]) == kl - 1 - ind) {
            continue;
        }
        ++ans;
        ind = kl - 1;
    }

    cout << ans << endl;
}
