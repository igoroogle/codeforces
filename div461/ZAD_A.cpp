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
int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int x, y;
    cin >> x >> y;
    if (y < 1) {
        cout << "No\n";
        return 0;
    }

    if (y - 1 > x) {
        cout << "No\n";
        return 0;
    }

    if (y == 1 && x > 0) {
        cout << "No\n";
        return 0;
    }

    if ((x - y + 1) % 2) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}
