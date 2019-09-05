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
typedef unsigned int uni;
const ll DL = 1E8 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    //cout << "smth\n";
    //cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll mn = min(ll(DL + 3), k);//uhu

    for (ll i = 2; i <= mn; ++i) {
        if (n % i != i - 1) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
