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
const int INF = 1E9;
int cnt[11];
void getS(string& s) {
    bool f = true;
    for (int i = 1; i < int(s.length()) - 1; ++i) {
        if (s[i] != '0') {
            f = false;
            break;
        }
    }
    if ((s[0] == '1') && (f) && (s[int(s.length()) - 1] <= '1')) {
        for (size_t i = 2; i < s.length(); ++i) {
            cout << '9';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < 10; ++i) {
        cnt[i] = 0;
    }

    for (size_t i = 0; i < s.length(); ++i) {
        ++cnt[s[i] - '0'];
    }
    int cht = 0, pos = 0;
    for (int i = 0; i < 10; ++i) {
        cht += cnt[i] % 2;
    }

    for (int i = int(s.length()) - 1; i >= 0; --i) {
        cht -= cnt[s[i] - '0'] % 2;
        --cnt[s[i] - '0'];
        cht += cnt[s[i] - '0'] % 2;
        f = true;
        for (int j = int(s[i] - '0') - 1; j >= 0; --j) {
            cht -= cnt[j] % 2;
            ++cnt[j];
            cht += cnt[j] % 2;
            if (pos >= cht) {
                f = false;
                s[i] = j + '0';
                break;
            }
            cht -= cnt[j] % 2;
            --cnt[j];
            cht += cnt[j] % 2;
        }
        if (f) {
            ++pos;
            continue;
        }

        pos = 0;
        for (size_t j = int(s.length()) - 1; j > i; --j) {
            while ((pos < 9) && (cnt[pos] % 2 == 0)) {
                ++pos;
            }

            --cnt[pos];
            s[j] = pos + '0';
        }
        cout << s << '\n';
        return;
    }

}
int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        getS(s);
    }
}
