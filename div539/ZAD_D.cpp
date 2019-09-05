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

bool check (int n, const string& s) {
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    string s, t;
    cin >> s;
    int n = s.length();
    if (n < 4) {
        cout << "Impossible\n";
        return 0;
    }

    bool f = true;
    for (int i = 1; i < n; ++i) {
        if ((n % 2) && (i == n / 2)) {
            continue;
        }

        if (s[i] != s[0]) {
            f = false;
            break;
        }
    }

    if (f) {
        cout << "Impossible\n";
        return 0;
    }


    for (int i = 1; i < n; ++i) {
        t =  s.substr(i, n - i) + s.substr(0, i);
        if (s == t) {
            continue;
        }
        if (check(n, t)) {
            cout << "1\n";
            return 0;
        }
    }

    cout << "2\n";
}
