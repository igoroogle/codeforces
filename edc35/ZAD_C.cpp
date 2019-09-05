#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
ll a[4];
int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);

    if ((a[0 == 2]) && (a[1] == 4) && (a[2] == 4)) {
        cout << "YES\n";
        return 0;
    }

    if ((a[0] == 2) && (a[1] == 3) && (a[2] == 3)) {
        cout << "NO\n";
        return 0;
    }

    if ((a[0] == 1) || (a[2] == 3) || (a[1] == 2)) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
}
