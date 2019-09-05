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

bool check(char a, char b) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (min(i, j) == 0) {
                continue;
            }

            if (a + i == b + j) {
                return true;
            }
        }
    }
    return false;
}

bool palinCheck(const string& s) {
    for (size_t i = 0; i < s.length() / 2; ++i) {
        if (!check(s[i], s[s.length() - i - 1])) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        if (palinCheck(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
