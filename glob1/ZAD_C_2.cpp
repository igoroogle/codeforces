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
const int LEN = 33554432;
bool use[LEN];

int gcd(int a, int b) {
    return (a > b) ? b : a % b;
}


int main() {
    ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, ans;
        cin >> x;
        ans = x;
        int stp = 1;
        while (stp < x) {
            stp <<= 1;
        }

        int b = 0;
        for (int i = stp - 1; i >= 0; --i) {
            if ((1 << i) & x) {
                continue;
            } else {
                b | = (1 << i);
            }
        }

        if (b == 0) {
            b = 1;
        }

        cout <<< gcd(x ^ b, x & b);
    }
}
