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
const ll MDL = 3E9;
const ll DL = 2E18 + 1;
ll a[200010], vl[200010], kl[200010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, k, m = 0, x;

    cin >> n >> k;
    while (n--) {
        cin >> x;
        if (x != 1) {
            ++m;
            vl[m] = vl[m - 1] + x;
            a[m] = x;
        } else {
            if (a[m] != ll(1)) {
                ++m;
                a[m] = 1;
                vl[m] = vl[m - 1];
            }
            ++vl[m];
            ++kl[m];
        }
    }
    n = m;

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll p = 1;
        for (int j = i; j <= n; ++j) {
            if (ll(sqrt(ld(p)) * sqrt(ld(a[j]))) > MDL) {
                break;
            }

            p *= a[j];
            if (p > DL) {
                break;
            }

            if (p % k != 0) {
                continue;
            }

            ll pp = p / k;
            ll sum = vl[j] - vl[i - 1];

            if (i == j) {
                if (a[i] != ll(1)) {
                    if (pp == sum) {
                        ++ans;
                    }
                    continue;
                }

                if (sum < pp) {
                    continue;
                }

                ans += sum - pp + ll(1);
                continue;
            }


            if (min(a[i], a[j]) != ll(1)) {
                if (pp == sum) {
                    ++ans;
                }
                continue;
            }

            ll ed = kl[i] + kl[j];
            sum -= ed;
            if (max(a[i], a[j]) != ll(1)) {
                if ((pp > sum) && (pp <= sum + ed)) {
                    ++ans;
                }
                continue;
            }

            if ((pp < sum + ll(2))) {
                continue;
            }

            pp -= sum;
            ll xx = kl[i];
            ll yy = kl[j];

            if (xx + yy < pp ) {
                continue;
            }

            if (xx > yy) {
                swap(xx, yy);
            }
            if (yy < pp) {
                pp -= yy;
                pp = xx - pp + ll(1);
                ans += pp;
                continue;
            }

            pp = min(pp - ll(1), xx);
            ans += pp;
        }
    }

    cout << ans << endl;
}
