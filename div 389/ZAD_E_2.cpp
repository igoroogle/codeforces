#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef long double ld;
using namespace std;
const int DL = 1E7 + 2;
int a[1000100], ans[10000010],  n, k, i;
bool prov(int x) {
    int i;
    int kl = 0;
    if (x == 0)
        return true;

    for (i = 0; i < x; ++i) {
        ans[i] = 0;
    }

    ans[x] = 1;
    for (i = x + 1; i <= DL; ++i) {
        ans[i] = max(1, ans[i >> 1] + ans[i - (i >> 1)]);
    }

    for (i = 0; i < n; ++i) {
        kl += ans[a[i]];
        if (kl >= k)
            return true;
    }

    if (kl >= k)
        return true;
    return false;
}


int main() {
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int l = 0, r = 1E7 + 2, m;
    while (l < r) {
        m = (l + r) >> 1;
        if (prov(m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (l - 1 == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << l - 1 << endl;
}
