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
bool t[10010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    int a = 1, b = 1, c = 1;
    t[1] = 1;
    while (c <= n) {
        c = a + b;
        a = b;
        b = c;
        t[c] = 1;
    }

    string s;
    s.resize(n);
    for (size_t i = 0; i < n; ++i) {
        if (t[i + 1]) {
            s[i] = 'O';
        } else {
            s[i] = 'o';
        }
    }

    cout << s << endl;
}
