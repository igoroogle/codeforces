#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
const ld EPS = 1E-12;
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int ans = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') ||
        (s[i] == 'u') || (s[i] == '0') || (s[i] == '2') ||(s[i] == '4') ||
        (s[i] == '6') || (s[i] == '8')) {
            ++ans;
        }
    }

    cout << ans << endl;
}
