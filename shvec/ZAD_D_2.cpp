#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector< vector<int> > a;
vector< vector<int> > ans(int l, int r);
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, i, j;
    cin >> n;
    a = ans(1, n);
    cout << a.size() << endl;
    for (i = 0; i < a.size(); i++)
    {
        printf("%d", a[i].size());
        for (j = 0; j < a[i].size(); j++)
            printf(" %d", a[i][j]);
        printf("\n");
    }
    return 0;
}

vector< vector<int> > ans(int l, int r)
{
    vector< vector<int> > c, a, b;
    vector <int> d;
    if (l == r)
        return c;
    int i, j, m;
    m = (l + r) / 2;
    a = ans(l, m);
    b = ans(m + 1, r);
    for (i = 0; i < max(a.size(),b.size()); i++)
    {
        if (a.size() <= i)
            c.push_back(b[i]);
        else if (b.size() <= i)
            c.push_back(a[i]);
        else
        {
            c.push_back(d);
            c[i].resize(a[i].size() + b[i].size());
            merge(a[i].begin(), a[i].end(), b[i].begin(), b[i].end(), c[i].begin());
        }
    }
    for (i = l; i <= m; i++)
        d.push_back(i);
    c.push_back(d);
    return c;
}
