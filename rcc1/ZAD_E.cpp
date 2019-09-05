#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned int uni;
typedef long double ld;
string a[311][311], b[311][311];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, lu = 0, ru = 0, ld = 0, rd = 0, tot0 = 0, down0 = 0, up1 = 0, right0 = 0, right1 = 0, tot1 = 0, lus = 0, rus = 0, lds = 0, rds = 0;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (auto cur : a[i][j]) {
                if (cur == '0') {
                    ++tot0;
                } else {
                    ++tot1;
                }
            }
        }
    }

    for (int j = 1; j < m - 1; ++j) {
        for (auto cur : b[n - 1][j]) {
            if (cur == '0') {
                ++down0;
            }
        }

        for (auto cur : b[0][j]) {
            if (cur == '1') {
                ++up1;
            }
        }
    }

    for (int i = 1; i < n - 1; ++i) {
        for (auto cur : b[i][n - 1]) {
            if (cur == '0') {
                ++right0;
            } else {
                ++right1;
            }
        }
    }

    ru = down0 + right0;
    lu = tot0 - ru;
    rd = up1 + right1;
    ld = tot1 - rd;

    vector<pair<pair<int, int>, pair<int, int>>> ans, ansv;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = a[i][j].length() - 1; k >= 0; --k) {
                if (a[i][j][k] == '0') {
                    if (i != 0) {
                        ans.em(mp(i + 1, j + 1), mp(1, j + 1));
                        if (j == 0) {
                            ++lus;
                        } else if (j == m - 1) {
                            ++rus;
                        } else if (lus < lu) {
                            ansv.em(mp(1, j + 1), mp(1, 1));
                            ++lus;
                        } else {
                            ansv.em(mp(1, j + 1), mp(1, m));
                            ++rus;
                        }
                    } else {
                        if (j == 0) {
                            ans.em(mp(1, 1), mp(1, m));
                            ++rus;
                        } else if (j == m - 1) {
                            ans.em(mp(1, m), mp(1, 1));
                            ++lus;
                        } else if (lus < lu) {
                            ans.em(mp(1, j + 1), mp(1, 1));
                            ++lus;
                        } else {
                            ans.em(mp(1, j + 1), mp(1, m));
                            ++rus;
                        }
                    }
                } else {
                    ///f
                    if (i != n - 1) {
                        ans.em(mp(i + 1, j + 1), mp(n, j + 1));
                        if (j == 0) {
                            ++lds;
                        } else if (j == m - 1) {
                            ++rds;
                        } else if (lds < ld) {
                            ansv.em(mp(n, j + 1), mp(n, 1));
                            ++lds;
                        } else {
                            ansv.em(mp(n, j + 1), mp(n, m));//se
                            ++rds;
                        }
                    } else {
                        if (j == 0) {
                            ans.em(mp(n, 1), mp(n, m));
                            ++rds;
                        } else if (j == m - 1) {
                            ans.em(mp(n, m), mp(n, 1));
                            ++lds;
                        } else if (lds < ld) {
                            ans.em(mp(n, j + 1), mp(n, 1));
                            ++lds;
                        } else {
                            ans.em(mp(n, j + 1), mp(n, m));
                            ++rds;
                        }
                    }
                }
            }
        }
    }

    for (auto cur : ansv) {
        ans.pb(cur);
    }


    /*
    //print


    for (auto cur : ans) {
        a[cur.y.x - 1][cur.y.y - 1] = a[cur.x.x - 1][cur.x.y - 1].substr(a[cur.x.x - 1][cur.x.y - 1].length() - 1, 1) + a[cur.y.x - 1][cur.y.y - 1];
        a[cur.x.x - 1][cur.x.y - 1].pop_back();
    }


    cout << "---\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << i + 1 << ' ' << j + 1 << ' ' << a[i][j] << ' ';
        }
        cout << '\n';
    }
    //printend
    //return 0;
    cout << lus << ' ' << rus << ' ' << lds << ' ' << rds << endl;
    return 0;*/

    /*for (auto cur : ans) {
        cout << cur.x.x << ' ' << cur.x.y << ' ' << cur.y.x << ' ' << cur.y.y << endl;
    }
    return 0;*/





    while (lus > lu) {
        ans.em(mp(1, 1), mp(1, m));
        --lus;
        ++rus;
    }

    while (rus > ru) {
        ans.em(mp(1, m), mp(1, 1));
        --rus;
        ++lus;
    }

    while (lds > ld) {
        ans.em(mp(n, 1), mp(n, m));
        --lds;
        ++rds;
    }

    while (rds > rd) {
        ans.em(mp(n, m), mp(n, 1));
        --rds;
        ++lds;
    }



    /*
    //print


    for (auto cur : ans) {
        a[cur.y.x - 1][cur.y.y - 1] = a[cur.x.x - 1][cur.x.y - 1].substr(a[cur.x.x - 1][cur.x.y - 1].length() - 1, 1) + a[cur.y.x - 1][cur.y.y - 1];
        a[cur.x.x - 1][cur.x.y - 1].pop_back();
    }


    cout << "---\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << i + 1 << ' ' << j + 1 << ' ' << a[i][j] << ' ';
        }
        cout << '\n';
    }
    //printend
    cout << lu << ' ' << lus << ' ' << ru << ' ' << rus << ' ' << ld << ' ' << lds << ' ' << rd << ' ' << rds << endl;
    return 0;
    */


    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            for (int k = b[i][j].length() - 1; k >= 0; --k) {
                if (b[i][j][k] == '0') {
                    ans.em(mp(1, 1), mp(1, j + 1));
                    ans.em(mp(1, j + 1), mp(i + 1, j + 1));
                    --lus;
                } else {
                    ans.em(mp(n, 1), mp(n, j + 1));
                    ans.em(mp(n, j + 1), mp(i + 1, j + 1));
                    --lds;
                }
            }
        }
    }


    /*
    //print


    for (auto cur : ans) {
        a[cur.y.x - 1][cur.y.y - 1] = a[cur.x.x - 1][cur.x.y - 1].substr(a[cur.x.x - 1][cur.x.y - 1].length() - 1, 1) + a[cur.y.x - 1][cur.y.y - 1];
        a[cur.x.x - 1][cur.x.y - 1].pop_back();
    }


    cout << "---\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << i + 1 << ' ' << j + 1 << ' ' << a[i][j] << ' ';
        }
        cout << '\n';
    }
    //printend
    return 0;*/


    for (int i = 1; i < n - 1; ++i) {
        for (int k = b[i][0].length() - 1; k >= 0; --k) {
            if (b[i][0][k] == '0') {
                ans.em(mp(1, 1), mp(i + 1, 1));
                --lus;
            } else {
                ans.em(mp(n, 1), mp(i + 1, 1));
                --lds;
            }
        }

        for (int k = b[i][m - 1].length() - 1; k >= 0; --k) {
            if (b[i][m - 1][k] == '0') {
                ans.em(mp(1, m), mp(i + 1, m));
                --rus;
            } else {
                ans.em(mp(n, m), mp(i + 1, m));
                --rds;
            }
        }
    }






    /*
    //print


    for (auto cur : ans) {
        a[cur.y.x - 1][cur.y.y - 1] = a[cur.x.x - 1][cur.x.y - 1].substr(a[cur.x.x - 1][cur.x.y - 1].length() - 1, 1) + a[cur.y.x - 1][cur.y.y - 1];
        a[cur.x.x - 1][cur.x.y - 1].pop_back();
    }


    cout << "---\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << i + 1 << ' ' << j + 1 << ' ' << a[i][j] << ' ';
        }
        cout << '\n';
    }
    //printend
    return 0;*/


    while (rus > 0) {
        ans.em(mp(1, m), mp(n, m));
        --rus;
    }

    while (rds > 0) {
        ans.em(mp(n, m), mp(1, m));
        --rds;
    }


    /*
    //print


    for (auto cur : ans) {
        a[cur.y.x - 1][cur.y.y - 1] = a[cur.x.x - 1][cur.x.y - 1].substr(a[cur.x.x - 1][cur.x.y - 1].length() - 1, 1) + a[cur.y.x - 1][cur.y.y - 1];
        a[cur.x.x - 1][cur.x.y - 1].pop_back();
    }


    cout << "---\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << i + 1 << ' ' << j + 1 << ' ' << a[i][j] << ' ';
        }
        cout << '\n';
    }
    //printend
    return 0;*/

    for (int j = 1; j < m - 1; ++j) {
        for (int k = b[0][j].length() - 1; k >= 0; --k) {
            if (b[0][j][k] == '0') {
                ans.em(mp(1, 1), mp(1, j + 1));
            } else {
                ans.em(mp(1, m), mp(1, j + 1));
            }
        }

        for (int k = b[n - 1][j].length() - 1; k >= 0; --k) {
            if (b[n - 1][j][k] == '1') {
                ans.em(mp(n, 1), mp(n, j + 1));
            } else {
                ans.em(mp(n, m), mp(n, j + 1));
            }
        }
    }

    /*
    //print

    for (auto cur : ans) {
        a[cur.y.x - 1][cur.y.y - 1] = a[cur.x.x - 1][cur.x.y - 1].substr(a[cur.x.x - 1][cur.x.y - 1].length() - 1, 1) + a[cur.y.x - 1][cur.y.y - 1];
        a[cur.x.x - 1][cur.x.y - 1].pop_back();
    }


    cout << "---\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << i + 1 << ' ' << j + 1 << ' ' << a[i][j] << ' ';
        }
        cout << '\n';
    }
    //printend
    return 0;*/

    int zer = 0, ed = 0;
    for (auto cur : b[0][0]) {
        if (cur == '0') {
            ++zer;
        }
    }

    for (auto cur : b[n - 1][m - 1]) {
        if (cur == '0') {
            ++zer;
        }
    }

    for (auto cur : b[0][m - 1]) {
        if (cur == '1') {
            ++ed;
        }
    }

    for (auto cur : b[n - 1][0]) {
        if (cur == '1') {
            ++ed;
        }
    }

    for (int i = 0; i < zer; ++i) {
        ans.em(mp(1, 1), mp(1, m));
    }

    for (int i = 0; i < ed; ++i) {
        ans.em(mp(n, 1), mp(n, m));
    }

    for (int k = b[0][0].length() - 1; k >= 0; --k) {
        if (b[0][0][k] == '0') {
            ans.em(mp(1, m), mp(1, 1));
        } else {
            ans.em(mp(n, 1), mp(1, 1));
        }
    }

    for (int k = b[0][m - 1].length() - 1; k >= 0; --k) {
        if (b[0][m - 1][k] == '0') {
            ans.em(mp(1, 1), mp(1, m));
        } else {
            ans.em(mp(n, m), mp(1, m));
        }
    }

    for (int k = b[n - 1][0].length() - 1; k >= 0; --k) {
        if (b[n - 1][0][k] == '0') {
            ans.em(mp(1, 1), mp(n, 1));
        } else {
            ans.em(mp(n, m), mp(n, 1));
        }
    }

    for (int k = b[n - 1][m - 1].length() - 1; k >= 0; --k) {
        if (b[n - 1][m - 1][k] == '0') {
            ans.em(mp(1, m), mp(n, m));
        } else {
            ans.em(mp(n, 1), mp(n, m));
        }
    }


    /*
    //print

    for (auto cur : ans) {
        a[cur.y.x - 1][cur.y.y - 1] = a[cur.x.x - 1][cur.x.y - 1].substr(a[cur.x.x - 1][cur.x.y - 1].length() - 1, 1) + a[cur.y.x - 1][cur.y.y - 1];
        a[cur.x.x - 1][cur.x.y - 1].pop_back();
    }


    cout << "---\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << i + 1 << ' ' << j + 1 << ' ' << a[i][j] << ' ';
        }
        cout << '\n';
    }
    //printend
    return 0;*/
    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur.x.x << ' ' << cur.x.y << ' ' << cur.y.x << ' ' << cur.y.y << '\n';
    }
}


/*

3 3
11 00 11
11 00 11
11 00 11
1 0 1
1 0 1
1111 0000 1111
*/
