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
map<string, string> an;
int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    string s, t;
    for (int i = 0; i < n; ++i) {
        cin >> s >> t;
        an[t] = s;
    }

    for (int i = 0; i < m; ++i) {
        cin >> s >> t;
        cout << s << ' ' << t << ' ';
        t.erase(t.size() - 1, 1);
        cout << '#';
        cout << an[t];
        cout << '\n';
    }
}
