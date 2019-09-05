#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const string w = "Bulbasaur";
const int DL = 100001;
int a[100010];
int main() {
    int i, j, n, x;
    cin >> n;
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        ++a[x];
        for (j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                ++a[j];
                if (x / j != j)
                    ++a[x / j];
            }
        }
    }

    int ans = 1;
    for (i = 2; i <= DL; ++i) {
        ans = max(ans, a[i]);
    }

    cout << ans << endl;
}
