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
int a[100010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int sm = 0;
    while (m--) {
        int x;
        cin >> x;
        --x;
        ++a[x];
        if (a[x] == 1) {
            ++sm;
        }

        if (sm == n) {
            cout << '1';
            sm = 0;
            for (int j = 0; j < n; ++j) {
                --a[j];
                if (a[j] > 0) {
                    ++sm;
                }
            }
        } else {
            cout << '0';
        }
    }
    cout << '\n';
}
