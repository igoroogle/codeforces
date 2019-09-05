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
const ll INF = 1E18;
int ar[258];
int main() {
    ios_base::sync_with_stdio(0);
    int n, a, b;
    cin >> n >> a >> b;
    --a;
    --b;
    if (a > b) {
        swap(a, b);
    }

    int rd = 0, kl = n;
    for (int i = 0; i < n; ++i) {
        ar[i] = i;
    }

    //cout << kl << endl;
    while (kl > 2) {
        ++rd;
        n = kl;
        kl = 0;
        for (int i = 1; i < n; i += 2) {
            //cout << ar[i - 1] << ' ' << ar[i] << endl;
            if ((ar[i - 1] == a) && (ar[i] == b)) {
                cout << rd << endl;
                return 0;
            } else if ((ar[i - 1] == a) || (ar[i] == a)) {
                ar[kl++] = a;
            } else if ((ar[i - 1] == b) || (ar[i] == b)) {
                ar[kl++] = b;
            } else {
                ar[kl++] = ar[i - 1];
            }
        }
    }

    cout << "Final!\n";
    return 0;
}
