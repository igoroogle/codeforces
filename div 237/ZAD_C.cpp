#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000;
pair <int, int> d[100010];
vector <int> a[100010];
int sum[100010];
int main()
{
    int n, k, m = 0, x, l = 0, r = 1, i, j;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        d[i] = make_pair(x, i);
    }
    sort(d, d + n);
    if (d[0].first > 0)
    {
        cout << -1 << endl;
        return 0;
    }
    while (r < n)
    {
        if (l == r)
        {
            cout << -1 << endl;
            return 0;
        }
        if ((sum[d[l].second] < k) && (d[l].first + 1 == d[r].first))
        {
            m++;
            if (m > INF)
            {
                cout << -1 << endl;
                return 0;
            }
            a[d[l].second].push_back(d[r].second);
            sum[d[l].second]++;
            sum[d[r].second]++;
            r++;
        }
        else l++;
    }
    cout << m << endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < a[i].size(); j++) printf("%d %d\n", i + 1, a[i][j] + 1);
    return 0;
}
