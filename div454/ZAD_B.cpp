#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[11][11];
int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> a[i][j];
        }
    }


    int x, y;
    cin >> x >> y;
    --x;
    --y;

    bool f = true;
    for (int i = (x % 3) * 3; i < (x % 3) * 3 + 3; ++i) {
        for (int j = (y % 3) * 3; j < (y % 3) * 3 + 3; ++j) {
            if (a[i][j] == '.') {
                f = false;
                a[i][j] = '!';
            }
        }
    }

    if (f) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (a[i][j] == '.') {
                    a[i][j] = '!';
                }
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        cout << a[i][0];
        for (int j = 1; j < 9; ++j) {
            if (j % 3 == 0) {
                cout << ' ';
            }
            cout << a[i][j];
        }
        cout << '\n';
        if (i % 3 == 2) {
            cout << '\n';
        }
    }
    return 0;
}
