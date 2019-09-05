#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    ll sm1 = 0, sm2 = 0, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sm1 += x;
    }

    for (int i = 0; i < n; ++i) {
        cin >> x;
        sm2 += x;
    }

    if (sm2 <= sm1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
