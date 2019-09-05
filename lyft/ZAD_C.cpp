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
int dp[100010], a[100010];
int rec(int x, int n) {
    if (dp[x] != 0) {
        return dp[x];
    }

    dp[x] = 2;
    for (int i = x - a[x]; i >= 0; i -= a[x]) {
        if (a[i] <= a[x]) {
            continue;
        }

        if (rec(i, n) == 2) {
            dp[x] = 1;
            return 1;
        }
    }

    for (int i = x + a[x]; i < n; i += a[x]) {


        if (a[i] <= a[x]) {
            continue;
        }

        if (rec(i, n) == 2) {
            dp[x] = 1;
            return 1;
        }
    }


    return 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (rec(i, n) == 1) {
            cout << 'A';
        } else {
            cout << 'B';
        }
    }

    cout << '\n';
}
