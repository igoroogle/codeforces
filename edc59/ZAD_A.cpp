#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if ((n == 2) && (s[0] >= s[1])) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << 2 << '\n';
            cout << s[0] << ' ' << s.substr(1, n - 1) << '\n';
        }
    }


}
