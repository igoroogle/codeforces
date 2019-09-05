#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
using namespace std;
typedef long long ll;
typedef long double ld;
bool vl[103];
int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 1; i <= 100; ++i) {
        for (int j = 0; j * 7 <= i; ++j) {
            if ((i - j * 7) % 3 == 0){
                vl[i] = true;
                break;
            }
        }
    }
    ll n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (vl[x]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
