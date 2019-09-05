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
    int b, k;
    cin >> b >> k;
    int ans = 0;
    b %= 2;
    int x;
    while (k > 1) {
        cin >> x;
        ans = (ans + b * x) % 2;
        --k;
    }

    cin >> x;
    ans = (ans + x) % 2;
    if (ans) {
        cout << "odd\n";
    } else {
        cout << "even\n";
    }
}
