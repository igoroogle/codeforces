#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
int dp[2][7000], jump[2][7000], n, k[3], kol[2][7000];
pair<int, int> q[14007];
bool use[2][7000];
int main() {
    cin >> n;
    int i, j, kk, p, sz;
    for (i = 0; i < 2; ++i) {
        scanf("%d", &k[i]);
        for (j = 0; j < k[i]; ++j) {
            scanf("%d", &jump[i][j]);
        }
    }

    for (i = 0; i < 2; ++i) {
        if (k[i] > 0) {
            sort(jump[i], jump[i] + k[i]);
        }

        kk = 1;
        if (k[i] == 0) {
            kk = k[i];
        }

        for (j = 1; j < k[i]; ++j) {
            if (jump[i][j] != jump[i][j - 1]) {
                jump[i][kk] = jump[i][j];
                ++kk;
            }
        }

        k[i] = kk;
    }

    dp[0][0] = 2;
    dp[1][0] = 2;

    q[0] = mp(0, 0);
    q[1] = mp(1, 0);
    sz = 2;
    pair<int, int> val;
    int nv;
    while (sz > 0) {

        val = q[0];
        --sz;
        for (i = 0; i < sz; ++i) {
            q[i] = q[i + 1];
        }

        for (i = 0; i < k[1 - val.x]; ++i) {
            nv = (val.y + n - jump[1 - val.x][i]) % n;

            if (use[1 - val.x][nv]) {
                continue;
            }

            if (dp[val.x][val.y] == 2) {
                use[1 - val.x][nv] = 1;
                dp[1 - val.x][nv] = 1;
                q[sz++] = mp(1 - val.x, nv);
                continue;
            }

            ++kol[1 - val.x][nv];
            if (kol[1 - val.x][nv] == k[1 - val.x]) {
                use[1 - val.x][nv] = 1;
                dp[1 - val.x][nv] = 2;
                q[sz++] = mp(1 - val.x, nv);
                continue;
            }
        }
    }

    for (i = 0; i < 2; ++i) {
        for (j = 1; j < n; ++j) {
            if (dp[i][j]  == 0) {
                printf("Loop ");
            } else if (dp[i][j] == 1) {
                printf("Win ");
            } else {
                printf("Lose ");
            }
        }
        printf("\n");
    }
}
