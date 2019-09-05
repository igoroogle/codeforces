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
    int a = 0, b = 0, x, y, n;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        if (x < 0) {
            ++a;
        } else {
            ++b;
        }
    }
    if ((a <= 1) || (b <= 1)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
