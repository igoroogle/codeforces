#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int main() {
    ll n, k;
    cin >> n >> k;
    if ((n / k) % ll(2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
