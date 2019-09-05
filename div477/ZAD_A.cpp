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
bool t[8000];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, s, h, m;
    cin >> n >> s;
    while (n--) {
        cin >> h >> m;
        t[h * 60 + m + 1441] = true;
    }

    for (int i = 1441; i < 6010; ++i) {
        bool f = true;
        for (int j = i - s; j <= i + s; ++j) {
            if (t[j]) {
                f = false;
                break;
            }
        }

        if (f) {
            cout << (i - 1441) / 60 << ' ' << (i - 1441) % 60 << endl;
            return 0;
        }
    }
}
