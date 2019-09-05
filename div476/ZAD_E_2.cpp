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
int getchar(char c) {
    return int(c - 'a');
}

struct bor {
    bool term;
    int len;
    bor *to[26];
    multiset<int> words;
    bor() {
        term = false;
        len = 0;
        words.clear();
        for (int i = 0; i < 26; ++i) {
            to[i] = nullptr;
        }
    }
};

void add(bor* b, const string& s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (b->to[getchar(s[i])] == nullptr) {
            b->to[getchar(s[i])] = new bor();
            b->to[getchar(s[i])]->len = b->len + 1;
        }
        b = b->to[getchar(s[i])];
    }
    b->term = true;
}


void dfs(bor* b) {
    for (int i = 0; i < 26; ++i) {
        if (b->to[i] != nullptr) {
            dfs(b->to[i]);
            for (auto cur : b->to[i]->words) {
                b->words.insert(cur);
            }
        }
    }

    if (b->term) {
        b->words.insert(-b->len);
    } else if (!b->words.empty()) {
        b->words.erase(b->words.begin());
        b->words.insert(-b->len);
    }
}

bor* b = new bor();


int main() {
    ios_base::sync_with_stdio(0);
    b->term = true;
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        add(b, s);
    }

    dfs(b);
    ll ans = 0;
    for (auto cur : b->words) {
        ans -= cur;
    }
    cout << ans << endl;
}
