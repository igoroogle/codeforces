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
    bool term, use;
    int cnt;
    bor *to[26], *par;
    bor() {
        term = false;
        use = false;
        cnt = 0;
        for (int i = 0; i < 26; ++i) {
            to[i] = nullptr;
        }
        par = nullptr;
    }
};

ll ans = 0;

void add(bor* b, const string& s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (b->to[getchar(s[i])] == nullptr) {
            b->to[getchar(s[i])] = new bor();
        }
        ++b->to[getchar(s[i])]->cnt;
        b = b->to[getchar(s[i])];
    }
    b->term = true;
    ans += s.length();
}


void dfs(bor* b, bor* par) {
    b->par = par;


    if (b->term) {
        par = b;
        while ((par->par != nullptr) && (!par->par->use)) {
            par = par->par;
            --ans;
        }
        par->use = true;
    }

    for (int i = 0; i < 26; ++i) {
        if (b->to[i] != nullptr) {
            dfs(b->to[i], b);
        }
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
    dfs(b, nullptr);
    cout << ans << endl;
}
