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
const ld PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;
const ld EPS = 1E-12;
ll x1[5], y1[5], x2[5], y2[5];
bool val[204][204], val2[204][204];
int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 4; ++i) {
        cin >> x1[i] >> y1[i];
        val[x1[i] + 101][y1[i] + 101] = true;
    }
    x1[4] = x1[0];
    y1[4] = y1[0];

    for (int i = 0; i < 4; ++i) {
        cin >> x2[i] >> y2[i];
        val2[x2[i] + 101][y2[i] + 101] = true;
    }
    x2[4] = x2[0];
    y2[4] = y2[0];

    int f = 0;

    for (int i = min(min(x1[0], x1[1]), min(x1[2], x1[3])); i <= max(max(x1[0], x1[1]), max(x1[2], x1[3])); ++i) {
        for (int j = min(min(y1[0], y1[1]), min(y1[2], y1[3])); j <= max(max(y1[0], y1[1]), max(y1[2], y1[3])); ++j) {
            //cout << i << ' ' << j << endl;
            if (val2[i + 101][j + 101]) {
                /*cout << j << endl;
                cout << i << ' ' << j << endl;*/
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
}
