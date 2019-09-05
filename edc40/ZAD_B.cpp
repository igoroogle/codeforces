#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned int uni;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    int n;
    cin >> n;
    int ans = n;
    cin >> s;
    for (int i = 1; i + i <= n; ++i) {
        if (s.substr(0, i) == s.substr(i, i)) {
            ans = min(ans, n - i + 1);
        }
    }
    cout << ans << endl;
}
