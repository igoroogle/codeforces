#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;
const int VAL = 3E8 + 7;

ll sum[5000010];
ll a[23], b[23], checktime = 0;

bool check(int n) {
    int i, j;
    ll sm = 0;
    for (i = 1; i < (1 << n) - 1; ++i) {
        ++checktime;
        for (j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sm += b[j];
                break;
            } else {
                sm -= b[j];
            }
        }
        if (sum[i] == sm) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(0));
    ios_base::sync_with_stdio(0);
    int n, i, j;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll sm = 0;
    for (i = 1; i < (1 << n) - 1; ++i) {
        for (j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sm += a[j];
                break;
            } else {
                sm -= a[j];
            }
        }
        sum[i] = sm;
    }

    for (i = 0; i < n; ++i) {
        b[i] = a[i];
    }

    bool f = true;
    reverse(b, b + n);
    while (checktime < VAL) {
        if (check(n)) {
            f = false;
            break;
        }
        random_shuffle(b, b + n);
        random_shuffle(b, b + n);
        random_shuffle(b, b + n);
        random_shuffle(b, b + n);
        random_shuffle(b, b + n);
        random_shuffle(b, b + n);
        random_shuffle(b, b + n);
        random_shuffle(b, b + n);
    }

    if (f) {
        cout << -1 << endl;
        return 0;
    }

    for (i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    return 0;
}