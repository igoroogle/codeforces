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

int main() {
    ios_base::sync_with_stdio(0);
    int x;
    cin >> x;
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= x; ++j) {
            if ((i % j == 0) && (i * j > x) && (i / j < x)) {
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }

    cout << -1 << '\n';
}
