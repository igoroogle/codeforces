#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
vector< pair<int, int> > reg[10100];
char s[100001][13];
int main()
{
    int n, m, i, j, id, bl, vl;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        scanf("\n%s%d%d", &s[i], &id, &bl);
        id--;
        if (reg[id].size() < 2)
        {
            reg[id].pb(mp(bl, i));
            /*if (reg[id][1] > reg[id][0])
                swap(reg[id][0], reg[id][1]);*/
            continue;
        }

        reg[id].pb(mp(bl, i));
        sort(reg[id].begin(), reg[id].end());
        reverse(reg[id].begin(), reg[id].end());
        vl = 3;
        if ((reg[id][1].x != reg[id][2].x))
            vl = 2;

        while (reg[id].size() > vl)
            reg[id].pop_back();

    }

    for (i = 0; i < m; i++)
    {
        if ((reg[i].size() > 2) && (reg[i][1].x == reg[i][2].x))
        {
            printf("?\n");
            continue;
        }
        printf("%s %s\n", s[reg[i][0].y], s[reg[i][1].y]);
    }

    return 0;
}
