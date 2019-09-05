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

struct Node() {
    int val;
    Node* next;
    Node* past;
    Node(int x) {
        next = nullptr;
        past = nullptr;
        val = x;
    }
};

int par[150100], len[150100], stp[150100];
vector<int> ed[150100];
Node* st[150100], fn[150100];

int getroot(int v) {
    if (par[v] == -1) {
        return v;
    }
    par[v] = getroot(par[v]);
    return par[v];
}


void unions(int u, int v) {


    if ((st[u] == nullptr) && (st[v] == nullptr)) {
        len[v] = 1;
        par[u] = v;
        st[v] = new Node(u);
        fn[v] = new Node(v);
        st[v]->next = fn[v];
        fn[v]->past = st[v];
        ed[u].pb(v);
        ed[v].pb(u);
        return;
    }

    int to_u = getroot(u);
    int to_v = getroot(v);
    if ((to_u == nullptr) || (to_v == nullptr)) {
        if (to_v == nullptr) {
            swap(u, v);
            swap(to_u, to_v);
        }
        par[u] = to_v;
        ed[u].pb(st[to_v]->val);
        ed[st[to_v]->val].pb(u);

    }

    par[v] = getroot(par[v]);
    return par[v];
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    fill(par, par + n, -1);
    fill (len, len + n, 0);
    fill (st, st + n, nullptr);
    fill (fn, fn + n, nullptr);

}
