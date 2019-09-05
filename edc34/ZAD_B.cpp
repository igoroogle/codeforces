#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    ll h1, a1, c1, h2, a2, x, y = 0;
    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;
    x = (h2 - 1) / a1 + 1;
    if ((x - 1) * a2 >= h1) {
        y = ((x - 1) * a2 - h1) / (c1 - a2) + 1;
    }
    cout << x + y << '\n';
    while (y--) {
        cout << "HEAL\n";
    }
    while (x--) {
        cout << "STRIKE\n";
    }
}
