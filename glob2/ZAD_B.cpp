#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int a[1010];
int main() {
    ios_base::sync_with_stdio(0);
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j > 0; --j) {
            if (a[j] <= a[j - 1]) {
                break;
            }
            swap(a[j], a[j - 1]);
        }
        int sum = 0;
        for (int j = 0; j <= i; j += 2) {
            sum += a[j];
        }
        if (sum > h) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << n << '\n';
}
