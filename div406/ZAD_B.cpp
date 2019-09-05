#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
int dp[2][7000], jump[2][7000], n, k[3], kol[2][7000];
pair<int, int> q[14007];
bool use[2][7000];
int main() {
    ll n = 131072;
    ll i = n, ans  = 0;
    while (i > 0) {
        ans += i;
        i /= 2;
    }

    cout << ans << endl;
}
