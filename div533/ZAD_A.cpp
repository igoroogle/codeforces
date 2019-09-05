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
int a[1010];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int t = 0, ans = 1E9;
    for (int k = 1; k <= 100; ++k) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == k) {
                continue;
            }
            sum += abs(a[i] - k) - 1;
        }
        if (sum < ans) {
            ans = sum;
            t = k;
        }
    }

    cout << t << ' ' << ans << '\n';
}
