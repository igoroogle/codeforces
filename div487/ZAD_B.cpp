#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool perPr(string s, int p, int n) {
    for (int i = p; i < n; ++i) {
        if (s[i] != s[i - p]) {
            return false;
        }
    }
    return true;
}

void updStr(string& s, int n, char c) {
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') {
            s[i] = c;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    string s, t;
    int n, p;
    cin >> n >> p >> s;
    bool f = false;
    for (int i = 0; i < n - p; ++i) {
        if (s[i] == s[i + p]) {
            if (s[i] != '.') {
                continue;
            }

            s[i] = '0';
            s[i + p] = '1';
            f = true;
            break;
        } else {
            if (s[i] != s[i + p]) {
                if (s[i] == '0') {
                    s[i + p] = '1';
                } else {
                    s[i] = '1';
                    s[i + p] = '0';
                }
                f = true;
                break;
            }
        }
    }

    if (!f) {
        cout << "No\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') {
            s[i] = '0';
        }
    }
    cout << s << '\n';
}
