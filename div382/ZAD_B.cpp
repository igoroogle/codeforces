#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll a[100010];
int main() {
    ll n, n1, n2, s1 = 0, s2 = 0, i;
    cin >> n >> n1 >> n2;
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }

    sort(a, a + n);
    reverse(a, a + n);
    if (n1 > n2) {
        swap(n1, n2);
    }


    for (i = 0; i < n1; ++i)
    {
        s1 += a[i];
    }

    for (i = n1; i < n1 + n2; ++i) {
        s2 += a[i];
    }

    cout << fixed << setprecision(11) << ld(s1) / ld(n1) + ld(s2) / ld(n2) << endl;
    return 0;
}
