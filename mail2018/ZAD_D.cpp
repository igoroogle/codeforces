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
const ll MOD = 3000000019;
const ll P = 223;
const ll DL = 5010;
ll pw[DL];

ll getChar(char c) {
    return ll(c - 'a');
}

ll get_hash(const vector<ll>& h, ll l, ll r) {
    ll ans = 0;
    if (l > 0) {
        ans = (h[l - 1] * pw[r - l + 1]) % MOD;
    }
    ans = (h[r] + MOD - ans) % MOD;
    return ans;
}

void build_hash(const string& s, vector<ll>& h) {
    h.resize(s.length());
    h[0] = getChar(s[0]);
    for (size_t i = 1; i < s.length(); ++i) {
        h[i] = (h[i - 1] * P + getChar(s[i])) % MOD;
    }
}


string a1[3010], a2[3010];
vector<ll> hs1[3010], hs2[3010];
ll lf[3010], rf[3010];


bool checkL(int n, ll x) {
    ll hs = -1, hss = -1;
    for (int i = 0; i < n; ++i) {
        if (lf[i] > rf[i]) {
            continue;
        }

        if (lf[i] - x < 0) {
            return false;
        }

        if (hs == -1) {
            hs = get_hash(hs1[i], lf[i] - x, rf[i]);
            hss = get_hash(hs2[i], lf[i] - x, rf[i]);
            continue;
        } else if ((hs != get_hash(hs1[i], lf[i] - x, rf[i])) || (hss != get_hash(hs2[i], lf[i] - x, rf[i]))) {
            return false;
        }
    }


    return true;
}

bool checkR(int n, ll x) {
    ll hs = -1, hss = -1;
    for (int i = 0; i < n; ++i) {
        if (lf[i] > rf[i]) {
            continue;
        }

        if (rf[i] + x >= ll(a1[i].size())) {
            return false;
        }

        if (hs == -1) {
            hs = get_hash(hs1[i], lf[i], rf[i] + x);
            hss = get_hash(hs2[i], lf[i], rf[i] + x);
            continue;
        } else if ((hs != get_hash(hs1[i], lf[i], rf[i] + x)) || (hss != get_hash(hs2[i], lf[i], rf[i] + x))) {
            return false;
        }
    }


    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    pw[0] = 1;
    for (ll i = 1; i < DL; ++i) {
        pw[i] = (pw[i - 1] * P) % MOD;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a1[i];
        build_hash(a1[i], hs1[i]);
    }

    for (int i = 0; i < n; ++i) {
        cin >> a2[i];
        build_hash(a2[i], hs2[i]);
    }


    ll hh1 = -1, hh2 = -1;
    int ind = -1;
    for (int i = 0; i < n; ++i) {
        rf[i] = a1[i].length() - 1;
        while ((lf[i] < ll(a1[i].length())) && (a1[i][lf[i]] == a2[i][lf[i]])) {
            ++lf[i];
        }

        while ((rf[i] >= 0) && (a1[i][rf[i]] == a2[i][rf[i]])) {
            --rf[i];
        }

        if (lf[i] > rf[i]) {
            continue;
        }

        ll hhh1 = get_hash(hs1[i], lf[i], rf[i]);
        ll hhh2 = get_hash(hs2[i], lf[i], rf[i]);
        if (ind == -1) {
            hh1 = hhh1;
            hh2 = hhh2;
            ind = i;
            continue;
        }

        if ((hh1 != hhh1) || (hh2 != hhh2)) {
            cout << "NO\n";
            return 0;
        }
    }

    //cout << h1 << ' ' << h2 << endl;
    if (ind == -1) {
        cout << "YES\n";
        cout << "a\na";
        return 0;
    }


    ll l = 1, r = 5001;
    while (l < r) {
        ll m = (l + r) >> ll(1);
        if (checkL(n, m)) {
            l = m + ll(1);
        } else {
            r = m;
        }
    }
    ll lef = l - ll(1);

    l = 1;
    r = 5001;
    while (l < r) {
        ll m = (l + r) >> ll(1);
        if (checkR(n, m)) {
            l = m + ll(1);
        } else {
            r = m;
        }
    }

    ll reff = l - ll(1);

    ll hasH = get_hash(hs1[ind], lf[ind] - lef, rf[ind] + reff);
    ll hasHH = get_hash(hs2[ind], lf[ind] - lef, rf[ind] + reff);
    ll len = rf[ind] + reff - (lf[ind] - lef) + ll(1);
    for (int i = 0; i < n; ++i) {
        if (lf[i] > rf[i]) {
            continue;
        }

        for (ll j = 0; j + len - ll(1) < ll(a1[i].size()); ++j) {
            if (get_hash(hs1[i], j, j + len - ll(1)) == hasH) {
                if ((lf[i] - lef != j) || (get_hash(hs2[i], j, j + len - ll(1)) != hasHH)) {
                    cout << "NO\n";
                    return 0;
                }
                break;
            }
        }

        string ss = a1[ind].substr(lf[i] - lef, len);
        string sn = a2[ind].substr(lf[i] - lef, len);
        for (ll i = 0; i < n; ++i) {
            auto pos = a1[i].find(ss);
            if (pos == string::npos) {
                if (lf[i] <= rf[i]) {
                    cout << "kek\n";
                    cout << a1[i] << endl;
                    cout << ss << endl;
                    return 0;
                }
                continue;
            }

            string sT;
            if (pos > 0) {
                sT = a1[i].substr(0, pos);
            }

            sT += sn;
            if (pos + 1 < a1[i].length()) {
                sT += a1[i].substr(pos + len, a1[i].length() - pos - len);
            }
            if (sT != a2[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    cout << a1[ind].substr(lf[ind] - lef, len) << '\n';
    cout << a2[ind].substr(lf[ind] - lef, len) << '\n';
}
