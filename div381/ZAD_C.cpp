#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
using namespace std;
const ll DL = 200010;
ll a[DL], dp[DL], ds[DL], pr[DL], ps[20][DL], pv[20][DL];
int main() {
    ll n, i;
    cin >> n;
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (i = 1; i < n; ++i) {
        scanf("%d", &pr[i]);
        --pr[i];
    }


}
