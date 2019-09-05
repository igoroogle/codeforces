#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int DL = 400010;
int h[DL], n, m, mx;
int mxval(int n, int m);
map < pair<int, int>, int> r;
int main()
{
    int i, sum = 0;
    cin >> n >> m;
    for (i = 1; i < DL; i++)
    {
        sum += i;
        if (sum > DL)
            break;
        h[sum] = i;
    }
    mx = mxval(n, m);
    cout << mx << endl;
    return 0;
}

int mxval(int i, int j)
{
    if ((i < 0) || (j < 0))
        return 0;
    int k = h[n - i + m - j] + 1;
    if ((k > i) && (k > j))
        return k - 1;
    int val = r[make_pair(k, j)];
    if (val != 0)
        return val - 1;
    val = max(mxval(i - k, j), mxval(i, j - k));
    r[make_pair(k, j)] = val + 1;
    return val;
}
