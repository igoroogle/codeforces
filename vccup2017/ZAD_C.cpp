#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
const int INF = 1E9;
char a[1003][1003];
int vl[1003][1003], l, r;
pair<int, int> b[1000010];
char s[1000010];
void go_next(int i, int j, int x, int y) {
    if ((a[x][y] == '*') || (vl[x][y] != INF)) {
        return;
    }

    vl[x][y] = vl[i][j] + 1;
    b[++r] = mp(x, y);
}

int main() {
    int n, m, k, i, j, sx, sy, kl = 0, x, y;
    cin >> n >> m >> k;

    for (i = 0; i < 1003; ++i){
        for (j = 0; j < 1003; ++j) {
            a[i][j] = '*';
            vl[i][j] = INF;
        }
    }

    for (i = 1; i <= n; ++i) {
        scanf("\n");
        for (j = 1; j <= m; ++j) {
            scanf("%c", &a[i][j]);
            if (a[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }

    vl[sx][sy] = 0;
    l = 0;
    r = 0;
    b[0] = mp(sx, sy);
    while (l <= r) {
        go_next(b[l].x, b[l].y, b[l].x + 1, b[l].y);
        go_next(b[l].x, b[l].y, b[l].x - 1, b[l].y);
        go_next(b[l].x, b[l].y, b[l].x, b[l].y + 1);
        go_next(b[l].x, b[l].y, b[l].x, b[l].y - 1);
        ++l;
    }

    x = sx;
    y = sy;
    while(k--) {
        if ((a[x + 1][y] != '*') && (vl[x + 1][y] <= k)) {
            s[kl++] = 'D';
            ++x;
        } else if ((a[x][y - 1] != '*') && (vl[x][y - 1] <= k)) {
            s[kl++] = 'L';
            --y;
        } else if ((a[x][y + 1] != '*') && (vl[x][y + 1] <= k)) {
            s[kl++] = 'R';
            ++y;
        } else if ((a[x - 1][y] != '*') && (vl[x - 1][y] <= k)) {
            s[kl++] = 'U';
            --x;
        } else {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    s[kl++] = '\0';
    printf("%s\n", s);
}
