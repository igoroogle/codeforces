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
    int t1;
    cin >> t1;
    while(t1--) {
        int n, s, t;
        cin >> n >> s >> t;
        cout << n - max(s, t) + 1 << '\n';
    }
}
