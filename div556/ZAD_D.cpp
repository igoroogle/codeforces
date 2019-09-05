#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
const int INF = 1E9 + 7;
vector<char> a[3];
int cnt[3][26];
int let_count[26], let_need[26];
bool use[26];

int main() {
    ios_base::sync_with_stdio(0);
    int f_let = 0;
    int n, q;
    string s;
    cin >> n >> q >> s;
    for (int i = 0; i < n; ++i) {
        ++let_need[s[i] - 'a'];
    }

    for (int i = 0; i < q; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            int t;
            char new_let;
            cin >> t >> new_let;
            --t;
            ++let_count[new_let - 'a'];
            ++cnt[t][new_let - 'a'];
            a[t].pb(new_let);
            if (!use[new_let - 'a']) {
                if ((let_count[new_let - 'a'] > let_need[new_let - 'a']) ||
                    (let_count[new_let - 'a'] != cnt[t][new_let - 'a'])) {
                    use[new_let - 'a'] = true;
                    ++f_let;
                }
            }
        } else {
            int t;
            cin >> t;
            --t;
            char old_let = a[t].back();
            a[t].pop_back();
            --let_count[old_let - 'a'];
            --cnt[t][old_let - 'a'];
            if ((use[old_let - 'a'])
                && (let_count[old_let - 'a'] <= let_need[old_let - 'a'])) {
                int max_vl = 0;
                for (int j = 0; j < 3; ++j) {
                    max_vl = max(max_vl, cnt[j][old_let - 'a']);
                }

                if (max_vl == let_count[old_let - 'a']) {
                    --f_let;
                    use[old_let - 'a'] = false;;
                }
            }
        }

        if (f_let) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
