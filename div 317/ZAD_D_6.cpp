#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 1000003;
ll rank1[DL], rank2[DL], parent1[DL], parent2[DL], weight[DL], hang1[DL], hang2[DL], sum[DL], n, m, t = 0;
vector<ll> elem[DL], val[DL];
void union1 (ll v, ll u);
void union2 (ll v, ll u);
ll getroot1(ll v);
ll getroot2(ll v);
ll getweight(ll v);
ll getans(ll v, ll time);
int main()
{
    ll i, x, y, u, v, change;
    char c;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        rank1[i] = 1;
        rank2[i] = 1;
        parent1[i] = -1;
        parent2[i] = -1;
        weight[i] = -1;
        hang1[i] = -1;
        hang2[i] = -1;
        sum[i] = 1;
    }
    for (i = 0; i < m; i++)
    {
        //scanf("\n%c", &c);
        cin >> c;
        if (c == 'U')
        {
            scanf("%I64d%I64d", &x, &y);
            x--;
            y--;
            u = getroot2(x);
            v = getroot2(y);
            if (u != v)
                union2(u, v);
        }
        else if (c == 'M')
        {
            scanf("%I64d%I64d", &x, &y);
            x--;
            y--;
            u = getroot1(x);
            v = getroot1(y);
            if (u != v)
                union1(u, v);
        }
        else if (c == 'A')
        {
             scanf("%I64d", &x);
             x--;
             u = getroot2(x);
             elem[u].push_back(t);
             if (val[u].size() == 0)
                val[u].push_back(sum[u]);
             else
                {
                    change = val[u][val[u].size() - 1] + sum[u];
                    val[u].push_back(change);
                }
        }
        else if (c == 'Z')
        {
            scanf("%I64d", &x);
            x--;
            weight[getroot1(x)] = t;
        }
        else if (c == 'Q')
        {
            scanf("%I64d", &x);
            x--;
            printf("%I64d\n", getans(x, getweight(x)));
        }
        t++;
    }
    return 0;
}

void union1 (ll v, ll u)
{
    if (rank1[v] > rank1[u])
    {
        parent1[u] = v;
        hang1[u] = t;
    }
    else if (rank1[v] < rank1[u])
    {
        parent1[v] = u;
        hang1[v] = t;
    }
    else
    {
        parent1[u] = v;
        hang1[u] = t;
        rank1[v]++;
    }
}

void union2 (ll v, ll u)
{
    if (rank2[v] > rank2[u])
    {
        parent2[u] = v;
        hang2[u] = t;
        sum[v] = sum[v] + sum[u];
    }
    else if (rank2[v] < rank2[u])
    {
        parent2[v] = u;
        hang2[v] = t;
        sum[u] = sum[v] + sum[u];
    }
    else
    {
        parent2[u] = v;
        hang2[u] = t;
        sum[v] = sum[v] + sum[u];
        rank2[v]++;
    }
}

ll getroot1(ll v)
{
    if (parent1[v] == -1) return v;
    return getroot1(parent1[v]);
}

ll getroot2(ll v)
{
    if (parent2[v] == -1) return v;
    return getroot2(parent2[v]);
}

ll getweight(ll v)
{
    if (parent1[v] == -1)
        return weight[v];
    ll val = getweight(parent1[v]);
    if (val < hang1[v])
        val = weight[v];
    return val;
}

ll getans(ll v, ll time)
{
    ll ans = 0, l, r, m;
    if (elem[v].size() > 0)
    {
        l = 0;
        r = elem[v].size() - 1;
        while (l < r)
        {
            m = (l + r) / 2;
            if (elem[v][m] < time) l = m + 1;
            else r = m;
        }
        if (elem[v][l] > time)
        {
            if (l == 0)
                ans += val[v][val[v].size() - 1];
            else
                ans += val[v][val[v].size() - 1] - val[v][l - 1];
        }
    }
    if (parent2[v] != -1)
        ans += getans(parent2[v], max(time, hang2[v]));
    return ans;
}
