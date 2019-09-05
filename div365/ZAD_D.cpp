#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
vector<int> q1[1000010], q2[1000010];
int ans[1000010], a[1000010], s[1000010], f[1000010], n, m;
map<int, int> t;

int get(int x);
void upd(int x, int vl);
int rmq(int l, int r);
int main()
{
    int i, j, l, r, pr, x;
    cin >> n;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &l, &r);
        q1[r].pb(l);
        q2[r].pb(i);
    }
    //cout << "--------\n";
    for (i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] ^ a[i];
        //cout << i << ' ' << (s[i] ^ s[i - 1]) << endl;
        pr = t[a[i]];
        if (pr != 0)
            upd(pr, a[i]);
        t[a[i]] = i;
        upd(i, a[i]);

        for (j = 0; j < q1[i].size(); j++)
        {
            l = q1[i][j];
            r = i;
            x = q2[i][j];
            ans[x] = s[r] ^ s[l - 1];
            ans[x] ^= rmq(l, r);
        }
    }

    for (i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return 0;
}

int get(int x)
{
    int i = x, sm = 0;
    while (i >= 0)
    {
        sm ^= f[i];
        i = (i & (i + 1)) - 1;
    }
    return sm;
}

void upd(int x, int vl)
{
    int i = x;
    while (i <= n)
    {
        f[i] ^= vl;
        i = i | (i + 1);
    }
}

int rmq(int l, int r)
{
    return (get(r) ^ get(l - 1));
}
