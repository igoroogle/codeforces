#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int ans = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        for (size_t j = i + 1; j < s.length(); ++j) {
            for (size_t k = j + 1; k < s.length(); ++k) {
                if ((s[i] == 'Q') && (s[j] == 'A') && (s[k] == 'Q')) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}
