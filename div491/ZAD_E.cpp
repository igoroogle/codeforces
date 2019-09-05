#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll f[30];
vector<int> a;
vector<pair<int, int>> an;
ll ans = 0;

void rec(size_t i, int sm, int zer, ll p) {
    if (i == an.size()) {
        ans += (sm - zer) * f[sm - 1] / p;
        return;
    }

    for (int j = 1; j <= an[i].y; ++j) {
        if (an[i].x == 0) {
            rec(i + 1, sm + j, j, p * f[j]);
        } else {
            rec(i + 1, sm + j, zer, p * f[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    f[0] = 1;
    for (int i = 1; i <= 20; ++i) {
        f[i] = f[i - 1] * ll(i);
    }

    ll n;
    cin >> n;
    while (n > ll(0)) {
        a.pb(int(n % ll(10)));
        n /= ll(10);
    }


    sort(a.begin(), a.end());
    an.em(a[0], 1);

    for (int i = 1; i < a.size(); ++i) {
        if (a[i] != a[i - 1]) {
            an.em(a[i], 1);
        } else {
            ++an.back().y;
        }
    }

    rec(0, 0, 0, 1);
    cout << ans << endl;
}
