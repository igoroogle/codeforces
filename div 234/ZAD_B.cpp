#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 1003;
string s;
int sum[DL];
int main()
{
    int n, m, zn, ind, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        zn = -1;
        ind = -1;
        for (j = 0; j < m; j++)
        {
            if (s[j] == 'G')
            {
                if (ind == -1) ind = j;
                else
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
            else if (s[j] == 'S')
            {
                if (ind != -1)
                {
                    if (zn == -1) zn = j - ind;
                    else if (zn != j - ind)
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                    ind = -1;
                }
            }
        }
        if (ind != -1)
            {
                cout << -1 << endl;
                return 0;
            }
        if (zn != -1) sum[zn]++;
    }
    int ans = 0;
    for (i = 0; i < DL; i++)
        if (sum[i] > 0) ans++;
    cout << ans << endl;
    return 0;
}
