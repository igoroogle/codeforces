#include<bits/stdc++.h>
using namespace std;
bool equals(string& s, string& s2) {
    if (s.length() != s2.length())
        return false;

    for (int i = 0; i < s.length(); ++i) {
        if ((s[i] != '?') || (s[i] != s2[i]))
            return false;
    }

    return true;
}

void to_equal(string& s, string& s2) {
    if (s.length() != s2.length()) {
        cout << "No\n";
        exit(0);
    }

    for (int i = 0; i < s.length(); ++i) {
        if ((s[i] != s2[i]))
            s[i] = '?';
    }
}

string a[311];
int ind[311];
int main() {
    int n, m, i;
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (i = 0; i < n)
    return 0;
}
