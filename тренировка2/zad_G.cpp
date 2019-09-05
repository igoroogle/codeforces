#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
typedef long long ll;

const int LEN = 500500;
const ll P = 2377;
map <pair <ll, ll>, ll > dp;
string ar[LEN];
int n, n1;
ll step, h, h1, res[LEN];

int main()
{
    freopen("list.in", "r", stdin);
    freopen("list.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        n1 = max(n1, (int)ar[i].length());

        h = h1 = 0;
        for (int j = 0; j < ar[i].length(); j++)
        {
            h = h * P + ar[i][j] - 'a' + 1;
            h1 = h1 * P + ar[i][ar[i].size() - j - 1] - 'a' + 1;

            dp[make_pair(h, h1)]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        h = h1 = 0;
        for (int j = 0; j < ar[i].length(); j++)
        {
            h = h * P + ar[i][j] - 'a' + 1;
            h1 = h1 * P + ar[i][ar[i].size() - j - 1] - 'a' + 1;

            res[j + 1] += (dp[make_pair(h, h1)] - 1);

            dp[make_pair(h, h1)]--;
        }
    }

    cout << n1 << endl;
    for (int i = 1; i <= n1; i++)
        cout << res[i] << endl;

    return 0;
}
