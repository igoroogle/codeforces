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

int main() {
    ios_base::sync_with_stdio(0);
    map<int, int> t;
    int n;
    cin >> n;
    int sum = 0, ans = 0;

    t[0] = 1;
    for (int i = 2; i <= n + 1; ++i) {
        int x;
        cin >> x;

        if (x == 1) {
            ++sum;
        } else {
            --sum;
        }

        if (t[sum] != 0) {
            ans = max(ans, i - t[sum]);
        } else {
            t[sum] = i;
        }
    }

    cout << ans << '\n';
}
