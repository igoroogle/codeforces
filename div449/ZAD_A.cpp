#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_beck
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
string s;
int main() {
    int n, m, l, r;
    char a, b;
    cin >> n >> m;
    cin >> s;
    while (m--) {
        cin >> l >> r >> a >> b;
        for (int i = l - 1; i < r; ++i) {
            if (s[i] == a) {
                s[i] = b;
            }
        }
    }
    cout << s << endl;
}
