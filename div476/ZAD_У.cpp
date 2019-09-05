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
ll a[200010], b[200010];
int main() {
    ios_base::sync_with_stdio(0);
    ll w, l, i;
    cin >> w >> l;
    a[0] = 2E9;
    a[w] = 2E9;
    for (int i = 1; i < w; ++i) {
        cin >> a[i];
    }

    b[0] = 2E9;

    int k = 1;
    for (int i = 0; i < w; ++i) {
        while ((b[i] > 0) && (k <= i + l)) {
            if (k <= i) {
                ++k;
                continue;
            }

            if (b[i] < a[k] - b[k]) {
                b[k] += b[i];
                b[i] = 0;
                break;
            }

            b[i] -= (a[k] - b[k]);
            b[k] = a[k];
            ++k;
        }
    }

    cout << b[w] << endl;
}
