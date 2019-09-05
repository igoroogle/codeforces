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
const int LEN = 900010;
const int INF = 2E9;

struct Node {
    Node *l, *r;
    int val;
    Node() {
        l = nullptr;
        r = nullptr;
        val = 0;
    }
};

void upd(Node* t, int l, int r, int ind, int x) {
    if (l == r) {
        t->val = max(t->val, x);
        return;
    }

    int m = (l + r) >> 1;

    if (ind <= m) {
        auto cp = t->l;
        t->l = new Node();
        if (cp != nullptr) {
            *(t->l) = *(cp);
        }
        upd(t->l, l, m, ind, x);
    } else {
        auto cp = t->r;
        t->r = new Node();
        if (cp != nullptr) {
            *(t->r) = *(cp);
        }
        upd(t->r, m + 1, r, ind, x);
    }

    if ((t->l == nullptr) || (t->r == nullptr)) {
        t->val = 0;
    } else {
        t->val = min(t->l->val, t->r->val);
    }

}

int get(Node* t, int l, int r, int tl, int tr) {

    if (tl > tr) {
        return INF;
    }

    if (t == nullptr) {
        return 0;
    }

    if ((tl == l) && (tr == r)) {
        return t->val;
    }

    int m = (l + r) >> 1;
    return min(get(t->l, l, m, tl, min(tr, m)), get(t->r, m + 1, r, max(tl, m + 1), tr));
}

Node* t[LEN];
int lv[LEN], rv[LEN], pv[LEN], vInd[LEN];
vector<pair<int, int>> segV[LEN];



int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    set<int> vl;
    vl.insert(0);
    vl.insert(1E9 + 1);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d%d", &lv[i], &rv[i], &pv[i]);
        vl.insert(lv[i]);
        vl.insert(rv[i]);
        vl.insert(rv[i] + 1);
    }

    int lenv = 0;
    map<int, int> indVl;
    while (!vl.empty()) {
        indVl[*vl.begin()] = lenv;
        vInd[lenv++] = *vl.begin();
        vl.erase(vl.begin());
    }

    for (int i = 0; i < k; ++i) {
        segV[indVl[rv[i]]].em(pv[i], lv[i]);
    }
    t[0] = new Node();
    for (int i = 0; i < lenv; ++i) {
        for (auto cur : segV[i]) {
            upd(t[i], 1, n, cur.x, cur.y);
        }
        t[i + 1] = new Node();
        *t[i + 1] = *t[i];
    }

    while(m--) {
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        int ind = (indVl.upper_bound(y)->y) - 1;
        if (get(t[ind], 1, n, a, b) >= x) {
            printf("yes\n");
            fflush(stdout);
        } else {
            printf("no\n");
            fflush(stdout);
        }
    }
}
