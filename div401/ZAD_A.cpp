#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll n, x;
    cin >> n >> x;
    while ((n > 0) && ((x != 0) || (n % 2 == 0))) {
        if (x == 1) {
            if (n % 2) {
                x = 0;
                --n;
            } else {
                x = 2;
                --n;
            }
        } else if (x == 0) {
            if (n % 2) {
                x = 1;
            }
            --n;
        } else {
            if (n % 2 == 0) {
                x = 1;
            }
            --n;
        }
    }

    n = n % 6;
    while (n > 0) {
        if (x == 1) {
            if (n % 2) {
                x = 0;
                --n;
            } else {
                x = 2;
                --n;
            }
        } else if (x == 0) {
            if (n % 2) {
                x = 1;
            }
            --n;
        } else {
            if (n % 2 == 0) {
                x = 1;
            }
            --n;
        }
    }


    cout << x << endl;
}
