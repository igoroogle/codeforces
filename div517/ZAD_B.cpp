#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef unsigned int uni;
typedef long long ll;
typedef long double ld;
int pr[4][100003], t[100003], a[100003], b[100003];
bool dp[4][100003];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < 4; ++i) {
        dp[i][n - 1] = true;
        pr[i][n - 1] = -1;
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (!dp[j][i + 1]) {
                continue;
            }

            for (int k = 0; k < 4; ++k) {
                if (dp[k][i]) {
                    continue;
                }

                if (((k | j) != a[i]) || ((k & j) != b[i])) {
                   continue;
                }

                dp[k][i] = true;
                pr[k][i] = j;
            }
        }
    }

    int ind = -1;
    for (int i = 0; i < 4; ++i) {
        if (dp[i][0]) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ind << ' ';
        ind = pr[ind][i];
    }
}
