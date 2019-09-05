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
char a[104][104];
int main() {
    ios_base::sync_with_stdio(0);
    int n, k, i, j;
    cin >> n >> k;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = '.';
        }
    }


    if (k % 2 == 0) {
        i = 1;
        while (k > 0) {
            a[1][i] = '#';
            a[2][i] = '#';
            k -= 2;
            ++i;
        }
    } else if (k >= n - 2) {
        for (int i = 1; i < n - 1; ++i) {
            a[1][i] = '#';
        }

        k -= (n - 2);
        if (k % 2) {
            a[j][n / 2] = '#';
            --k;
        }

        i = 1;
        while (k > 0) {
            a[j][i] = '#';
            a[j][n - i - 1] = '#';
            k -= 2;
            ++i;
        }
    }

    if (k % 2) {
        a[j][n / 2] = '#';
        --k;
    }

    i = 1;
    while (k > 0) {
        a[j][i] = '#';
        a[j][n - i - 1] = '#';
        k -= 2;
        ++i;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << '\n';
    }

}
