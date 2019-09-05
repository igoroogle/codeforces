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

int main() {
    ios_base::sync_with_stdio(0);
    ll w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    cout << ll(4) + ll(h1 + h2 + w1) * ll(2) << '\n';
}
