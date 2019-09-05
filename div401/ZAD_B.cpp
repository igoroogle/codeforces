#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
string a, b, bb;
int n, mn = 1E9, mx = 0;
void to_next() {
    int x = b[0], i;
    for (i = 0; i < n - 1; ++i) {
        b[i] = b[i + 1];
    }

    b[n - 1] = x;
}

void get_ans() {
    int i, ans1 = 0, ans2 = 0;
    for (i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            ++ans2;
        } else if (a[i] > b[i]) {
            ++ans1;
        }
    }

    mn = min(ans1, mn);
    mx = max(ans2, mx);
}

int main() {
    cin >> n >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bb = b;
    get_ans();
    to_next();
    while (b != bb) {
        get_ans();
        to_next();
    }

    int i = 0, j = 0, ans = 0;
    while (j < n) {
        if (a[i] < b[j]) {
            ++ans;
            ++i;
            ++j;
            continue;
        }

        ++j;
    }

    mx = max(ans, mx);

    cout << mn << "\n" << mx << endl;
}
