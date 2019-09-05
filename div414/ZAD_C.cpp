#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
string s, t;
char an[300010];
int main() {
    ios_base::sync_with_stdio(0);
    cin >> s >> t;
    int n, i, l, r, l1, r1, l2, r2;
    n = s.length();
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    l = 0;
    r = n - 1;
    l1 = 0;
    r1 = (n - 1) / 2;
    l2 = 0;
    r2 = n / 2 - 1;

    for (i = 0; i < n; ++i) {

        if (i & 1) {
            if (i == n - 1) {
                an[l] = t[l2];
                ++l;
                ++l2;
                continue;
            }

            if (s[l1] >= t[l2]) {
                an[r] = t[r2];
                --r2;
                --r;
            } else {
                an[l] = t[l2];
                ++l2;
                ++l;
            }
        } else {
            if (i == n - 1) {
                an[l] = s[l1];
                ++l;
                ++l1;
                continue;
            }

            if (s[l1] >= t[l2]) {
                an[r] = s[r1];
                --r1;
                --r;
            } else {
                an[l] = s[l1];
                ++l1;
                ++l;
            }
        }
    }
    cout << an << endl;
}
