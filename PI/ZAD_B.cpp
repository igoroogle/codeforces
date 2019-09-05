#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
bool use[1000010], use2[1000010];
int a[110];
char b[110];
int main()
{
    int n, i, sum = 0, maxv;
    cin >> n;
    for (i = 0; i < n; i++) cin >> b[i] >> a[i];
    for (i = 0; i < n; i++)
    {
        if ((b[i] == '-') && (!use2[a[i]]))
        {
            sum++;
            use[a[i]] = 1;
        }
        use2[a[i]] = 1;
    }
    maxv = sum;
    for (i = 0; i < n; i++)
    {
        if (b[i] == '-') sum--;
        else sum++;
        if (sum > maxv) maxv = sum;
    }
    cout << maxv << endl;
    return 0;
}
