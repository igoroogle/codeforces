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
int a[1002], b[1002];
int main() {
    ios_base::sync_with_stdio(0);
    int n, s;
    cin >> n >> s;
    --s;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    if ((a[0] == 0) || (a[s] + b[s] == 0)) {
        cout << "NO\n";
        return 0;
    } else if (a[s] == 1) {
        cout << "YES\n";
        return 0;
    }

    for (int i = s + 1; i < n; ++i) {
        if (a[i] + b[i] == 2) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}
