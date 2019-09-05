#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
bool happy(int x) {
    return (((x / 10 == 7) || (x % 10 == 7)));
}

int main() {
    ios_base::sync_with_stdio(0);
    ll x, hh, mm, ans = 0, h, m, vl;
    cin >> x >> hh >> mm;
    vl = hh * 60 + mm;
    while ((!happy(vl / 60)) && (!happy(vl % 60)))  {
        ++ans;
        vl = (vl + 1440 - x) % 1440;
    }
    cout << ans << endl;
}
