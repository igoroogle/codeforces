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

bool check(int a, int b, int c) {
    return ((a < b + c) && (b < a + c) && (c < a + b));
}

int main() {
    ios_base::sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    while (!check(a, b, c)) {
        if (a <= min(b, c)) {
            ++a;
        } else if (b <= min(a, c)) {
            ++b;
        } else if (c <= min(a, b)) {
            ++c;
        }
        ++ans;
    }
    cout << ans << '\n';
}
