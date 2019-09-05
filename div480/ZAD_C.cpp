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
int col[257];
int main() {
    ios_base::sync_with_stdio(0);
    int n, k, x;
    cin >> n >> k;
    for (int i = 0; i < 257; ++i) {
        col[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (col[x] != -1) {
            cout << col[x] << ' ';
            continue;
        }

        for (int j = max(0, x - k + 1); j <= x; ++j) {
            if (col[j] == -1) {
                col[j] = j;
            }

            if (x - col[j] + 1 <= k) {
                for (int p = col[j]; p <= x; ++p) {
                    col[p] = col[j];
                }
                break;
            }
        }
        cout << col[x] << ' ';
    }

}
