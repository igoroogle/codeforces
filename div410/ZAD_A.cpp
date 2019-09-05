#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
    int i, ans = 0;
    cin >> s;
    for (i = 0; i < s.length() / 2; ++i) {
        if (s[i] != s[s.length() - i - 1]) {
            ++ans;
        }
    }

    if ((ans == 1) || ((ans == 0) && (s.length() % 2))) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
