#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int kol[27];
vector<char> a, b, c;
char ans[2][13];
int main() {
    string s;
    char cc;
    cin >> s;
    int n = s.length(), i, j, fr = -1, sr = -1, l1, l2, l3, l, x, y;
    for (i = 0; i < n; ++i) {
        ++kol[s[i] - 'A'];
    }

    for (i = 0; i < n; ++i) {
        if (kol[i] == 2)
            cc = char(i + 'A');
    }

    for (i = 0; i < n; ++i) {
        if (s[i] == cc) {
            if (fr == -1) {
                fr = i;
            } else {
                sr = i;
            }
        }
    }


    if (sr == fr + 1) {
        cout << "Impossible\n";
        return 0;
    }

    if (fr > 0) {
        for (i = 0; i < fr; ++i) {
            a.push_back(s[i]);
        }
    }


        for (i = fr + 1; i < sr; ++i) {
            b.push_back(s[i]);
        }

    if (sr < n - 1) {
        for (i = sr + 1; i < n; ++i) {
            c.push_back(s[i]);
        }
    }

    if (!a.empty()) {
        reverse(a.begin(), a.end());
    }


    //------
    x = 0;
    y = 0;
    l = 0;
    for (i = b.size() / 2 - 1; i >= 0; --i) {
        ans[0][y] = b[i];
        ++y;
    }

    y = 0;
    for (i = b.size() / 2; i < b.size() / 2 * 2; ++i) {
        ans[1][y] = b[i];
        ++y;
    }


    if (b.size() % 2) {
        ans[x][y] = b[b.size() - 1];
        if (x == 0)
            x = 1;
        else {
            x = 0;
            ++y;
        }
    }

    ans[x][y] = cc;
    if (x == 0)
        x = 1;
    else {
        x = 0;
        ++y;
    }

    l1 = 0;
    l2 = 0;
    while (y < 13) {
        if (l1 < a.size()) {
            ans[x][y] = a[l1];
            ++l1;
            if (x == 0)
                x = 1;
            else {
                x = 0;
                ++y;
            }
        }

        if (l2 < c.size()) {
            ans[x][y] = c[l2];
            ++l2;
            if (x == 0)
                x = 1;
            else {
                x = 0;
                ++y;
            }
        }
    }

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 13; ++j) {
            cout << ans[i][j];
        }
        cout << endl;
    }


}
