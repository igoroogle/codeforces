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
const ll INF = 1E18 + 3;
const ll DL = 31623;
ll f[5010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }

    for (int i = 1; i <= n; ++i) {
        int a = i;
        int b = f[a];
        int c = f[b];
        if ((a != b) && (b != c) && (c != a) && (f[c] == a)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
