#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    int k, vl = 0;
    char c = 'a';
    cin >> k;
    cout << c;
    while (k > 0) {
        ++vl;
        if (vl > k) {
            vl = 0;
            ++c;
            cout << c;
            continue;
        }
        cout << c;
        k -= vl;
    }
    cout << endl;
}
