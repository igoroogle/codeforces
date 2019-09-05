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
int ans[] = {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341,
            89, 1365, 1, 5461, 4681, 21845, 1, 87381,
            1, 349525, 299593, 1398101, 178481, 5592405, 1082401};


int main() {
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int stp = 1;
        while ((1 << stp) <= x) {
            ++stp;
        }

        if ((1 << stp) - 1 != x) {
            cout << (1 << stp) - 1 << '\n';
            continue;
        }
        cout << ans[stp] << '\n';
    }
}
