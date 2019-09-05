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
const int INF = 1E9;

int main() {
    ios_base::sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    int ans = 0, num = INF;
    for (int i = 0; i < n; ++i) {
        int s, d;
        cin >> s >> d;
        while (s < t) {
            s += d;
        }
        if (num > s - t) {
            num = s - t;
            ans = i + 1;
        }
    }

    cout << ans << '\n';
}
