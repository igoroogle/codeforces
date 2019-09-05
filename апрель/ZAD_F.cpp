#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010];
int main() {
    ll n, i;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }//fgfgdfdfdfdfdfgdfdsfsdfdfdfddfdsdfsdfsd
}
