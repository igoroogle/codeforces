#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, m, h = 0, a1, b1;
struct xyz
{
        int x, y, z;
        bool operator<(const xyz& b) const
        {
            return ((x < b.x) || ((x == b.x) && (y < b.y)) || ((x == b.x) && (y == b.y) && (z < b.z)));
        }
};
map <xyz, int> a;
int rec(int i, int j, int num);
int main()
{
    int i, n1, m1;
    cin >> n >> m;
    n1 = n;
    m1 = m;
    i = 1;
    while (i <= max(n, m))
    {
        if ((m < i) || ((n < m) && (n >= i)))
        {
            n -= i;
            h += i;
        }

        else if (m >= i)
        {
            m -= i;
            h += i;
        }
        i++;
    }
    cout << h << ' ' << i - 1 << ' ' << n << ' ' << m << endl;
    n = n1;
    m = m1;
    h = i - 1;
    //cout << rec(n, m, h) << endl;

}

int rec(int i, int j, int num)
{
    if ((i < 0) || (j < 0))
        return 0;
    xyz t;
    t.x = i;
    t.y = j;
    t.z = num;
    if (num == 1)
    {
        if ((i > 0) && (j > 0))
            return 2 % MOD;
        if (i + j > 0)
            return 1 % MOD;
        return 0;
    }
    int val = a[t], ans;
    if (val != 0)
        return val - 1;
    val = (rec(i - num, j, num - 1) + rec(i, j - num, num - 1)) % MOD;
    a[t] = val + 1;
}
