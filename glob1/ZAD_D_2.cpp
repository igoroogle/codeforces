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
    freopen("input.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    for (ull i = 0; i <= ull(64); ++i) {
        ull mask = (ull(1) << i);
        if (i == ull(64)) {
            mask = ~ull(0);
        } else {
            --mask;
        }
        ull ans = 1;
        for (ull j = 2; j * j <= mask; ++j) {
            if (mask % j == ull(0)) {
                ans = mask / j;
                break;
            }
        }
        cout << ans << ", ";
    }
}
