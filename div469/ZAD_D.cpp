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
int a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        a[i + i] = i + 1;
    }

    /*for (int i = 0; i < n + n - 1; ++i) {
        cout << a[i] << ' ';
    }
    return 0;*/

    int mxind = n + n - 2;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = mxind - 1; j >= 0; --j) {
            if (a[j] == 0) {
                swap(a[mxind], a[j]);
                break;
            }
        }
        while (a[mxind] == 0) {
            --mxind;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}
