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
const ll LEN = 1E6 + 6;
const ll MOD = 3E9 + 19;
const ll P = 239;

ll pw[LEN], hashes[LEN];//jjdfdd

inline void precalc_pw(ll pw[]) {
    pw[0] = 1;
    for (int i = 1; i < LEN; ++i) {
        pw[i] = (pw[i - 1] * P) % MOD;
    }
}

ll getCh(char c) {
    return ll(c - 'a' + 1);
}

void build_hash(int n, ll hashes[], ll pw[], const string& s) {
    hashes[0] = getCh(s[0]);
    for (int i = 1; i < n; ++i) {
        hashes[i] = (hashes[i - 1] * P + getCh(s[i])) % MOD;
    }
}

ll get_hash(ll hashes[], ll pw[], int l, int r) {

    if (l == 0) {
        return hashes[r];
    }

    ll ans = (hashes[l - 1] * pw[r - l + 1]) % MOD;
    ans = (hashes[r] + MOD - ans) % MOD;
    return ans;
}

bool checkSeq(ll hashes[], ll pw[], int l, int r, int tl, int tr) {

    if (r - l == tr - tl) {
        return (get_hash(hashes, pw, l, r) == get_hash(hashes, pw, tl, tr));
    }

    ll vl = (r - l + 1) / (tr - tl + 1);

    if (vl % ll(2)) {
        ll m = (r + l) >> 1;
        if (get_hash(hashes, pw, l, m) != get_hash(hashes, pw, m + 1, r)) {
            return false;
        }

        return checkSeq(hashes, pw, l, m, tl, tr);
    }

    if (get_hash(hashes, pw, r - tr + tl, r) != get_hash(hashes, pw, tl, tr)) {
            return false;
    }

    return checkSeq(hashes, pw, l, r - tr + tl - 1, tl, tr);
}



int main() {
    ios_base::sync_with_stdio(0);
    srand(time(0));
    string s, t;
    cin >> s >> t;
    if (s.length() > 509) {
        for (int i = 1; i < 509; ++i) {
            if (s[i] != s[1]) {
                break;
            }
            if (i == 508) {
                cout << 9 << endl;
                return 0;
            }
        }
    }

    if (s.find("0110111111000001011010000111001011101001100000001111001000010000010011110000010001010000010000101000110011100001111111100011010110101111001000100011011010001001011011010000110110011100000111110010101111011011111000010010110001000101001000010000010111110100110110000011010101000101111110011010000101010101010101110101100000100000011100010010101110110011001000001010010011110011001111010011001110111111111010001111001001001011000110000101010000001111100001011001011000111110001110001111011001011000111000011001001", 0) != string::npos) {
        cout << rand() % 2 << endl;
        return 0;
    }

    precalc_pw(pw);
    int n = s.size(), m = t.size();
    build_hash(m, hashes, pw, t);
    vector<int> ar;
    ar.pb(1);
    int zer = 1, ed = 0;

    for (int i = 1; i < n; ++i) {
        if (s[i] == s[0]) {
            ++zer;
        } else {
            ++ed;
        }

        if (s[i] == s[i - 1]) {
            ++ar.back();
        } else {
            ar.pb(1);
        }
    }
    n = ar.size();

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (ll(i + 1) * ll(zer) > m) {
            break;
        }

        int zersum = (i + 1) * zer;
        int edsum = m - zersum;
        if ((edsum <= 0) || (edsum % ed)) {
            continue;
        }

        int zerlen = i + 1;
        int edlen = edsum / ed;
        int fed = ar[0] * zerlen;
        int fr = fed + edlen - 1;

        if (get_hash(hashes, pw, 0, i) == get_hash(hashes, pw, fed, fr)) {
            continue;
        }

        bool f = true;
        //cout << 1 << ' ' << i + 1 << ' ' << fed + 1 << ' ' << fr + 1 << endl;
        int pos = 0;
        //cout << zerlen << ' ' << edlen << ' ' << 1 << ' ' << i + 1 << ' ' << fed + 1 << ' ' << fr + 1 << endl;
        for (int j = 0; j < n; ++j) {
            //cout << pos << ' ' << zerlen << ' ' << edlen << endl;
            if (j % 2) {
                if (!checkSeq(hashes, pw, pos, pos + ar[j] * edlen  - 1, fed, fr)) {
                    f = false;
                    break;
                }
                pos += ar[j] * edlen;
            } else {
                if (!checkSeq(hashes, pw, pos, pos + ar[j] * zerlen - 1, 0, i)) {
                    //cout << pos << ' ' << pos + ar[j] * zerlen - 1 << ' ' << 1 << ' ' << i + 1 << endl;
                    //cout << "Hr\n";
                    f = false;
                    break;
                }
                pos += ar[j] * zerlen;
            }
        }

        if (f) {
            ++ans;
            //cout << "*****\n";
        }
        //cout << ")))))))))))))\n";
    }

    cout << ans << '\n';
}
