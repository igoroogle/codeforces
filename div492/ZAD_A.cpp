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
int a[11];
int main() {
    ios_base::sync_with_stdio(0);
    int n, sum = 0, an, msk = 0, kl = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    bool f = false;
    for (int i = 1; i < (1 << n) - 1; ++i) {
        msk = i;
        an = sum;
        kl = 0;
        for (int j = 0; j < n; ++j) {
            if ((1 << j) & i) {
                an -= a[j];
                ++kl;
            }
        }

        if ((sum - an > 0) && (an > 0) && (sum - an != an)) {
            f = true;
            break;
        }
    }

    if (!f) {
        cout << -1 << endl;
        return 0;
    }

    cout << kl << endl;
    for (int i = 0; i < n; ++i) {
        if ((1 << i) & msk) {
            cout << i + 1 << ' ';
        }
    }
}
