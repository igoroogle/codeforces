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
        --stp;
        int ans = 0;
        for (int i = 0; i < 25; ++i) {
            if ((1 << i))
        }
    }
}
