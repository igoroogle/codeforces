#include<iostream>
#include<iomanip>
#include<utility>
#include<cmath>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    int n, x, st = 0, ans = 1, vans = 0, ch = 0;
    cin >> n;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            ans *= i;
            int cur = 0;
            while (n % i == 0) {
                //cout << i << ' ';
                n /= i;
                ++cur;
            }

            if ((cur & (cur - 1)) != 0) {
                ch = 1;
            }

            if ((st != 0) && (cur != st)) {
                ch = 1;
            }
            st = max(cur, st);
        }
        ++i;
    }

    if (n > 1) {
        st = max(1, st);
        if (st != 1) {
            ch = 1;
        }
        ans *= n;
    }


    while ((st & (st - 1)) != 0) {
        ++st;
    }

    while (st > 1) {
        st /= 2;
        ++vans;
    }

    vans += ch;
    cout << ans << ' ' << vans << '\n';
}