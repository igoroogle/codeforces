#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
pair<int, int> a[1010];
int main() {
    ios_base::sync_with_stdio(0);
    int n, a1, b1, c1, d1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a1 >> b1 >> c1 >> d1;
        a[i] = mp(-(a1 + b1 + c1 + d1), i);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (a[i].y == 0) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}
