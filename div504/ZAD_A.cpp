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
    string s, t;
    int n, m;
    cin >> n >> m;
    cin >> s >> t;
    int coun0 = 0, coun1 = 0;

    for (int i = 0; i < min(n, m); ++i) {
        if (s[i] != t[i]) {
            break;
        }
        ++coun0;
    }

    for (int i = 0; i < min(n, m); ++i) {
        if (s[n - i - 1] != t[m - i - 1]) {
            break;
        }
        ++coun1;
    }

    if (s.find("*") != string::npos) {
        int val = s.find("*");
        if ((val <= coun0) && (n - val - 1 <= coun1) && (n - 1 <= m)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return 0;
    } else {
        if (s == t) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return 0;
    }
}
