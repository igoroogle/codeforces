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
const int LEN = 5201;
char a[LEN][LEN], b[LEN][LEN];
bool row[LEN], col[LEN];

int get_c(char c) {
    if (isalpha(c)) {
        return 10 + int(c - 'A');
    } else {
        return int(c - '0');
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    char c;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 4; ++j) {
            cin >> c;
            int x = get_c(c);
            for (int k = 3; k >= 0; --k) {
                a[i][j * 4 + k] = (x & 1) + '0';
                b[j * 4 + k][i] = (x & 1) + '0';
                x >>= 1;
            }
        }
    }


    /*cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }*/

    row[0] = true;
    col[0] = true;
    for (int i = 1; i < n; ++i) {
        row[i] = true;
        col[i] = true;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != a[i - 1][j]) {
                //cout << "False " << i << ' ' << j << endl;
                //cout << "False " << a[i][j] << ' ' << a[i][j - 1] << endl;
                row[i] = false;
            }

            if (b[i][j] != b[i - 1][j]) {
                //cout << "False " << i << ' ' << j << endl;
                //cout << "False " << b[i][j] << ' ' << b[i][j - 1] << endl;
                col[i] = false;
            }
        }
    }

    for (int i = n; i >= 1; --i) {
        if (n % i) {
            continue;
        }

        bool f = true;
        for (int j = 0; j < n / i; ++j) {
            if (!f) {
                break;
            }

            for (int k = 1; k < i; ++k) {
                if ((!row[j * i + k]) || (!col[j * i + k])) {
                    f = false;
                    //cout << i << ' ' << j * i + k << endl;
                    //cout << row[j * i + k] << endl;
                    //cout << col[j * i + k] << endl;
                    break;
                }
            }
        }

        if (f) {
            cout << i << '\n';
            break;
        }
    }
}
