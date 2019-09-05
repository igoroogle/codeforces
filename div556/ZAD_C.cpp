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
typedef pair<int, int> pii;
const int INF = 1E9 + 7;


int main() {
    ios_base::sync_with_stdio(0);
    int n, ones = 0, twos = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            ++ones;
        } else {
            ++twos;
        }
    }

    if (twos > 0) {
        cout << "2 ";
        --twos;
    }

    if (ones > 0) {
        cout << "1 ";
        --ones;
    }

    for (int i = 0; i < twos; ++i) {
        cout << "2 ";
    }

    for (int i = 0; i < ones; ++i) {
        cout << "1 ";
    }
}
