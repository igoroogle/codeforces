#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
const int DL = 10002;
typedef long long ll;
int gr[DL], sm[DL];
bool mx[DL];
int main() {
    freopen("divide-heaps.in", "r", stdin);
    freopen("divide-heaps.out", "w", stdout);
    for (int i = 3; i < DL; ++i) {
        for (int j = 1; j < i - j; ++j) {
            mx[gr[j] ^ gr[i - j]] = true;
            if ((gr[j] ^ gr[i - j]) == 0) {
                ++sm[i];
            }
        }

        int k = 0;
        while (mx[k]) {
            ++k;
        }
        gr[i] = k;
        for (int j = 1; j < i - j; ++j) {
            mx[gr[j] ^ gr[i - j]] = false;
        }
    }

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << sm[n] << '\n';
    }
}
