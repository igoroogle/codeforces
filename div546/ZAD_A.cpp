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
typedef pair<int, int> pii;
pair<int, int> a[111];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }

    int m;
    cin >> m;
    for (int i = 0; i < n; ++i) {
        if (a[i].y < m) {
            continue;
        }
        if (a[i].y >= m) {
            cout << n - i << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
}
