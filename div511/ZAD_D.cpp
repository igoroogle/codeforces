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

ll getAns(ll n) {
    ll ans = n - (n % ll(6));
    n = n % ll(6);
    if (n < 4) {
        return ans;
    }

    return (ans + (n - ll(3)) * ll(2));
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    cout << getAns(n * m) << endl;
}
