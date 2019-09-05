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
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, md;
    cin >> n >> m;
    md = 1;
    while (n--) {
        if (md > 100000000) {
            break;
        }
        md <<= ll(1);
    }

    cout << m % md << endl;
}
