#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
const ll MOD = 1E9 + 7;
const int LEN = 100010;


ll gcd(ll a, ll b) {
    if (a == ll(0)) {
        return b;
    }

    if (b == ll(0)) {
        return a;
    }

    return gcd(b, a % b);
}
ll ans = 0;

struct Node {
    int num;
    ll val;
    Node *last, *next;

    Node(int num, ll val) {
        this->num = num;
        this->val = val;
        last = nullptr;
        next = nullptr;
    }

    Node(Node *last, Node *next, int num, ll val) {
        this->num = num;
        this->val = val;
        this->last = last;
        this->next = next;
    }
};

Node *start = nullptr, *finish = nullptr;


struct rollBack {
    pair<Node*, Node*> insback;
    Node* delback;
    bool type;

    rollBack(pair<Node*, Node*> insback) {
        this->insback = insback;
        delback = nullptr;
        type = true;
    }

    rollBack(Node* delback) {
        this->delback = delback;
        insback = mp(nullptr, nullptr);
        type = false;
    }
};

vector<rollBack> rb;


void ins(Node*  cur, Node* val) {
    if (cur == nullptr) {
        if (start == nullptr) {
            start = val;
            finish = val;
            return;
        }
        start->last = val;
        val->next = start;
        start = val;
        return;
    }
    val->last = cur;
    val->next = cur->next;
    if (cur->next != nullptr) {
        cur->next->last = val;
        cur->next = val;
    } else {
        cur->next = val;
        finish = val;
    }
}

void insback(Node* cur, Node* val) {
    ins(cur, val);
    rb.em(val);
}

void del(Node* cur) {
    if (cur->last != nullptr) {
        cur->last->next = cur->next;
    }

    if (cur->next != nullptr) {
        cur->next->last = cur->last;
    }

    if (start == cur) {
        start = cur->next;
    }

    if (finish == cur) {
        finish = cur->last;
    }
}

void delback(Node* cur) {
    rb.em(mp(cur->last, cur));
    del(cur);
}

void roll_back(size_t p) {
    while (rb.size() > p) {
        if (rb.back().type) {
            ins(rb.back().insback.x, rb.back().insback.y);
        } else {
            del(rb.back().delback);
            delete(rb.back().delback);
        }
        rb.pop_back();
    }

    for (auto cur = start; cur != nullptr; cur = cur->next) {
        --(cur->num);
    }
}




vector<int> ed[LEN];

ll x[LEN];

void print_it() {
    cout << "pirnt it : ";
    for (auto cur = start; cur != nullptr; cur = cur->next) {
        cout << cur->num << ' ' << cur->val <<  " : ";
    }
    cout << endl;
}

ll count_it(int h) {
    ll ans = 0;
    int prevnum = 0;
    ll prevval = 0;
    for (auto cur = start; cur != nullptr; cur = cur->next) {
        ans = (ans + ll(cur->num - prevnum) * prevval) % MOD;
        prevnum = cur->num;
        prevval = cur->val;
    }

    if (finish != nullptr) {
        ans = (ans + ll(h - finish->num) * finish->val) % MOD;
    }
    return ans;
}

void dfs(int v, int p, int h) {
    auto rbval = rb.size();
    Node* cur = new Node(0, x[v]);

    insback(nullptr, cur);
    ll prevval = 0;
    int prevnum = 0;
    ll vans = 0;
    while (cur != nullptr) {
        ++(cur->num);
        auto next_cur = cur->next;
        ll curval = gcd(prevval, cur->val);
        int curnum = cur->num;
        if (curval == prevval) {
            delback(cur);
        } else if (curval != cur->val) {
            Node *addv = new Node(curnum, curval);
            insback(cur, addv);
            delback(cur);
        }
        cur = next_cur;
        prevval = curval;
        prevnum = curnum;
    }

    ++h;
    ans = (count_it(h) + ans) % MOD;

    for (auto u : ed[v]) {
        if (p == u) {
            continue;
        }
        dfs(u, v, h);
    }

    roll_back(rbval);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ed[u].pb(v);
        ed[v].pb(u);
    }


    dfs(0, -1, 1);
    cout << ans << '\n';
}