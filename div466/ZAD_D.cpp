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
const ll VL = 1000000000;

ll a[100010];
string b;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, zer = 4, ed = 0, mnl = -VL, mxl = VL, mnr = -VL, mxr = VL;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> b;

    for (int i = 4; i < n; ++i) {
        if (b[i] == '0') {
            if ((zer != 0) && (zer < 4)) {
                ++zer;
                continue;
            }
            if (zer == 0) {
                ed = 0;
                zer = 1;
                mxr = min(a[i] - ll(1), mxr);
                mxr = min(a[i - 1] - ll(1), mxr);
                mxr = min(a[i - 2] - ll(1), mxr);
                mxr = min(a[i - 3] - ll(1), mxr);
                mxr = min(a[i - 4] - ll(1), mxr);
                continue;
            }
            mxl = min(a[i], mxl);
            mxl = min(a[i - 1], mxl);
            mxl = min(a[i - 2], mxl);
            mxl = min(a[i - 3], mxl);
            mxl = min(a[i - 4], mxl);
        } else {
            if ((ed != 0) && (ed < 4)) {
                ++ed;
                continue;
            }

            if (ed == 0) {
                ed = 1;
                zer = 0;
                mnl = max(a[i] + ll(1), mnl);
                mnl = max(a[i - 1] + ll(1), mnl);
                mnl = max(a[i - 2] + ll(1), mnl);
                mnl = max(a[i - 3] + ll(1), mnl);
                mnl = max(a[i - 4] + ll(1), mnl);
                continue;
            }
            mnr = max(a[i], mnr);
            mnr = max(a[i - 1], mnr);
            mnr = max(a[i - 2], mnr);
            mnr = max(a[i - 3], mnr);
            mnr = max(a[i - 4], mnr);
        }
    }

    cout << mnl << ' ' << mxr << endl;
}
