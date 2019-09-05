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
int a[11];
int main() {
    ios_base::sync_with_stdio(0);
    map<int, bool> pr;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int x;
    while (m--) {
        cin >> x;
        pr[x] = true;
    }

    for (int i = 0; i < n; ++i) {
        if (pr[a[i]]) {
            cout << a[i] << ' ';
        }
    }
}
