#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
using namespace std;
typedef long long ll;
typedef long double ld;
bool vl[10000003];
int main() {
    ios_base::sync_with_stdio(0);
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    a *= 10;
    while (!vl[a]) {
        vl[a] = true;
        ++ans;
        if (a / b == c) {
            cout << ans << endl;
            return 0;
        }
        a = (a % b) * 10;
    }
    cout << -1 << endl;
}
