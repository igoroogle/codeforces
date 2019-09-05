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
const int INF = 1E9;
const int DL = 111;
int a[DL];

int main() {
    ios_base::sync_with_stdio(0);
    int n, d, x;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++a[x];
    }

    for (int i = 1; i < DL; ++i) {
        a[i] += a[i - 1];
    }

    int ans = 0;
    for (int i = d + 1; i < DL; ++i) {
        ans = max(ans, a[i] - a[i - d - 1]);
    }
    cout << n - ans << endl;
}
