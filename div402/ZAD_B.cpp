#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int a[7], b[7];
int main() {
    int n, k, ans = 0, i = 0;
    cin >> n >> k;
    if (n == 0) {
        i = k;
    }

    while ((i < k) && (n != 0)) {
        if (n % 10 == 0) {
            ++i;
        }
        else {
            ++ans;
        }

        n /= 10;
    }

    if (i < k) {
        ans = i + ans - 1;
    }

    cout << ans << endl;
}
