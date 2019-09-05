#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
    ios_base::sync_with_stdio(0);
    int i, n, ans = 0;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s[0] == 'T') {
            ans += 4;
        } else if (s[0] == 'C') {
            ans += 6;
        } else if (s[0] == 'O') {
            ans += 8;
        } else if (s[0] == 'D') {
            ans += 12;
        } else if (s[0] == 'I') {
            ans += 20;
        }
    }

    cout << ans << endl;
}
