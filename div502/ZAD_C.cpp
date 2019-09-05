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
    cin >> n;
    for (int i = n / 2 + 1; i <= n; ++i) {
        cout << i << ' ';
    }

    for (int i = 1; i <= n / 2; ++i) {
        cout << i << ' ';
    }
}
