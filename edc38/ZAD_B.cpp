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
const ll INF = 2E18 + 3;
const int DL = 1000001;
int n;
int a[DL];
bool check(int x) {
    int ans = 0;
    for (int i = 0; i < DL; ++i) {
        if ((i - 1 <= x) || (DL - i - 1 <= x)) {
            ans += a[i];
        }
    }
    if (ans == n) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++a[x];
    }
    int l = 0, r = DL, m;
    while (l < r) {
        m = (l + r) >> 1;
        if (!check(m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l << endl;
}
