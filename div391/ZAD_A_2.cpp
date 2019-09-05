#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const string w = "Bulbasaur";
string s;
int main() {
    ios_base::sync_with_stdio(0);
    int i, ans = 0, cr = 0;
    cin >> s;
    for (i = 0; i < s.length(); ++i) {
        if (s[i] == w[cr]) {
            cr = (cr + 1) % w.length();
            if (cr == 0) {
                ++ans;
            }
        }

    }

    cout << ans << endl;
}
