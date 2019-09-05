#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_beck
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string fi1 = "What are you doing while sending \"";
const string fi2 = "\"? Are you busy? Will you send \"";
const string fi3 = "\"?";
const ll DL = 100010;
ll f[DL];
const ll INF = ll(3E18) + ll(2);
char get(ll n, ll k) {
    if (f[n] < k) {
        return '.';
    }

    if (n == 0) {
        return f0[k - ll(1)];
    }

    if (k <= ll(fi1.length())) {
        return fi1[k - ll(1)];
    }

    if (k <= ll(fi1.length()) + f[n - 1]) {
        return get(n - 1, k - ll(fi1.length()));
    }

    if (k <= ll(fi1.length()) + f[n - 1] + ll(fi2.length())) {
        return fi2[k - ll(fi1.length()) - f[n - ll(1)] - ll(1)];
    }

    if (k <= ll(fi1.length()) + f[n - 1] + ll(fi2.length()) + f[n - 1]) {
        return get(n - 1, k - ll(fi1.length()) - f[n - 1] - ll(fi2.length()));
    }

    return fi3[k - ll(fi1.length()) - f[n - 1] - ll(fi2.length()) - f[n - 1] - ll(1)];
}

int main() {
    ios_base::sync_with_stdio(0);
    f[0] = f0.length();
    for (ll i = 1; i < DL; ++i) {
        f[i] = fi1.length() + f[i - 1] + fi2.length() + f[i - 1] + fi3.length();
        if (f[i] > INF) {
            f[i] = INF;
        }
    }

    ll q, n, k;
    cin >> q;
    while (q--) {
        cin >> n >> k;
        cout << get(n, k);
    }
}
