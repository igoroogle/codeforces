#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    a = n;
    b = n;
    while (a % 10) {
        ++a;
    }

    while (b % 10) {
        --b;
    }

    if (abs(a - n) <= abs(b - n)) {
        cout << a << '\n';
    } else {
        cout << b << '\n';
    }
}
