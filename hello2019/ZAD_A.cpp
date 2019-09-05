#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    string s, t;
    cin >> s;
    int n = 5;
    while (n--) {
        cin >> t;
        if (t[0] == s[0] || t[1] == s[1]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
