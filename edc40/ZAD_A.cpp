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
    int ans = 0, n;
    string s;
    cin >> n;
    cin >> s;
    int i = 0;
    while (i + 1 < n) {
        if ((s.substr(i, 2) == "UR") || (s.substr(i, 2) == "RU")) {
            ++ans;
            i += 2;
            continue;
        }
        ++i;
    }
    cout << n - ans << endl;
}
