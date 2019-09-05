#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
const int LEN = 26;

vector<pii> cor[LEN];

bool check1(vector<pii>& ar) {
    int n = ar.size();
    for (int i = 1; i < n; ++i) {
        if ((ar[i - 1].x != ar[i].x) || (ar[i - 1].y + 1 != ar[i].y)) {
            return false;
        }
    }
    return true;
}

bool check2(vector<pii>& ar) {
    int n = ar.size();
    for (int i = 1; i < n; ++i) {
        if ((ar[i - 1].x + 1 != ar[i].x) || (ar[i - 1].y != ar[i].y)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < LEN; ++i) {
            cor[i].clear();
        }

        vector<vector<char>> a(n), b(n);
        vector<vector<int>> goDown(n), goRight(n);
        for (int i = 0; i < n; ++i) {
            a[i].resize(m);
            b[i].resize(m);
            goDown[i].resize(m);
            goRight[i].resize(m);
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                b[i][j] = '.';
                goDown[i][j] = 1;
                goRight[i][j] = 1;
                if (a[i][j] != '.') {
                    cor[a[i][j] - 'a'].em(i, j);
                }
            }
        }

            bool f = true;
            int td = 0;
            for (int i = 25; i >= 0; --i) {
                if (cor[i].empty()) {
                    if (td != 0) {
                        f = false;
                        break;
                    }
                    continue;
                }

                if (td == 0) {
                    td = i + 1;
                }


                if (cor[i].size() == 1) {
                    if (b[cor[i].back().x][cor[i].back().y] == '.') {
                        b[cor[i].back().x][cor[i].back().y] = i + 'a';
                    }
                    continue;
                }

                if (check1(cor[i])) {
                    int x = cor[i].front().x;
                    int y = cor[i].front().y;
                    int z = cor[i].back().y;
                    while (y <= z) {
                        if (b[x][y] == '.') {
                            b[x][y] = i + 'a';
                        }
                        int tmp = y;
                        y += goDown[x][y];
                        goDown[x][tmp] = max(goDown[x][tmp], z - tmp + 1);
                    }
                }

                if (check2(cor[i])) {
                    int x = cor[i].front().x;
                    int y = cor[i].front().y;
                    int z = cor[i].back().x;
                    while (x <= z) {
                        if (b[x][y] == '.') {
                            b[x][y] = i + 'a';
                        }
                        int tmp = x;
                        x += goRight[x][y];
                        goRight[tmp][y] = max(goRight[tmp][y], z - tmp + 1);
                    }
                }

                f = false;
                break;
            }

            if (!f) {
                cout << "NO\n";
                continue;
            }

            for (int i = 0; i < n; ++i) {
                if (!f) {
                    break;
                }
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] != b[i][j]) {
                        f = false;
                        break;
                    }
                }
            }

            if (!f) {
                cout << "NO\n";
                continue;
            }

            cout << "YES\n";
            cout << td << '\n';
            for (int i = 0; i < td; ++i) {
                cout << cor[i].front().x + 1 << ' ' << cor[i].front().y + 1 << ' ';
                cout << cor[i].back().x + 1 << ' ' << cor[i].back().y + 1 << '\n';
            }
    }
}