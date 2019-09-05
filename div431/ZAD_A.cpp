#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int a[110];
int main() {
    ios_base::sync_with_stdio(0);
    int n, i;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if ((a[0] % 2 == 0) || (a[n - 1] % 2 == 0)) {
        cout << "No\n";
        return 0;
    }

    if (n % 2) {
        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";
}
