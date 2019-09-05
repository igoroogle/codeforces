#include<iostream>
#include<iomanip>
#include<utility>
#include<cmath>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
int a[1003];

int main() {
    ios_base::sync_with_stdio(0);
    int ans = 0, vans = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (a[0] == 1) {
        ++vans;
    }

    for (int i = 1; i < n; ++i) {
        if (a[i - 1] + 1 == a[i]) {
            ++vans;
        } else {
            vans = 1;
        }

        if (a[i] == 1000) {
            ++vans;
        }

        ans = max(ans, vans - 2);
    }

    cout << ans << '\n';
}