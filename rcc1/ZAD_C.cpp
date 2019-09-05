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

pair<int, int> a[1010];
int vl[1010];

int l[1010], r[1010];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    for (int i = 0; i < n; ++i) {
        a[i] = mp(-l[i] - r[i], i);
    }

    sort(a, a + n);

    int wr = 0;
    for (int i = 0; i < n; ++i) {
        if ((i == 0) || (a[i - 1].x < a[i].x)) {
            ++wr;
        }
        vl[a[i].y] = wr;
    }

    for (int i = 0; i < n; ++i) {
        int lf = 0, rf = 0;
        for (int j = 0; j < i; ++j) {
            if (vl[j] > vl[i]) {
                ++lf;
            }
        }

        if (lf != l[i]) {
            cout << "NO\n";
            return 0;
        }

        for (int j = i + 1; j < n; ++j) {
            if (vl[j] > vl[i]) {
                ++rf;
            }
        }

        if (rf != r[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << vl[i] << ' ';
    }
}
