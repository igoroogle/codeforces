#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    for (int i = 0; i < int(s.length()) - 2; ++i) {
        set<char> an;
        an.insert(s[i]);
        an.insert(s[i + 1]);
        an.insert(s[i + 2]);
        if ((an.find('.') == an.end()) && (an.size() == 3)) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
}
