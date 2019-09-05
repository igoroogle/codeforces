#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
string a, b, c, d;
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> a >> b >> n;
    cout << a << ' ' << b << endl;
    while (n--) {
        cin >> c >> d;
        if (c == a) {
            a = d;
        } else if (c == b) {
            b = d;
        } else if (d == a) {
            a = c;
        } else if (d == b) {
            b = c;
        }
        cout << a << ' ' << b << endl;
    }
}
