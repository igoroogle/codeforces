#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    string ans = "";
    string a, b, s;
    cin >> a >> b;
    for (size_t i = 1; i <= a.length(); ++i) {
        for (size_t j = 1; j <= b.length(); ++j) {
            s = a.substr(0, i) + b.substr(0, j);
            if ((ans == "") || (s < ans)) {
                ans = s;
            }
        }
    }
    cout << ans << '\n';
}
