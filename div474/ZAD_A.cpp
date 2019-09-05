#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
string s;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    int a = 0, b = 0, c = 0, st = 0, fn = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] != 'a') {
            break;
        }
        ++st;
        ++a;
    }

    fn = int(s.length()) - 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] != 'c') {
            break;
        }
        --fn;
        ++c;
    }

    for (int i = st; i <= fn; ++i) {
        if (s[i] != 'b') {
            cout << "NO\n";
            return 0;
        }
        ++b;
    }


    if ((a == 0) || (b == 0)) {
        cout << "NO\n";
        return 0;
    }

    if (a + b + c != s.length()) {
        cout << "NO\n";
        return 0;
    }

    if ((a != c) && (b != c)) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
}
