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
typedef unsigned int uni;

int getchar(char c) {
    return c - 'a';
}

struct bor {
    bor* to[2];
    int state;
    bor() {
        for (int i = 0; i < 2; ++i) {
            to[i] = NULL;
        }
        state = 0;
    }
};


bool add(uni n, bor* b) {
    for (int i = 30; i >= 0; --i) {
        uni j = (uni(1) << uni(i)) & n;
        if (j != uni(0)) {
            j = 1;
        }

        if (b->to[j] == NULL) {
            b->to[j] = new bor();
        }
        ++(b->to[j]->state);
        b = b->to[j];
    }
}

uni get(uni n, bor* b) {
    uni ans = 0;
    for (int i = 30; i >= 0; --i) {
        uni j = (uni(1) << uni(i)) & n;
        if (j != uni(0)) {
            j = 1;
        }

        if (b->to[0] == NULL) {
            b->to[0] = new bor();
        }

        if (b->to[1] == NULL) {
            b->to[1] = new bor();
        }
        if (b->to[j]->state == 0) {
            j = uni(1) - j;
        }

        if (j != 0) {
            ans |= (uni(1) << i);
        }
        b = b->to[j];
        --(b->state);
    }
    return ans;
}


bor* b = new bor();
uni a[300010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    uni x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> x;
        add(x, b);
    }

    for (int i = 0; i < n; ++i) {
        cout << (get(a[i], b) ^ a[i]) << ' ';
    }
}
