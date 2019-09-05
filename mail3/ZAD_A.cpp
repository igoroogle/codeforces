#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
int kl[110];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int r;
        cin >> r;
        while (r--) {
            int x;
            cin >> x;
            ++kl[x];
        }
    }

    for (int i = 0; i < 107; ++i) {
        if (kl[i] == n) {
            cout << i << ' ';
        }
    }
}
