#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <ctime>
#include <set>

using namespace std;

#define ll long long
#define ld long double

const int N = (int)5e5 + 40;
const int INF = 30000;
const ld EPS = 1e-7;

int a[N], b[N], c[N];
string aa, bb, cc;

int main()
{
    int n, m, k, ans = 0, e = 0;
    cin >> aa;
    cin >> bb >> cc;
    n = aa.size();
    m  = bb.size();
    k = cc.size();
    for (int i = 0; i < n; i++)
        a[aa[i] - 'a']++;
    for (int i = 0; i < m; i++)
        b[bb[i] - 'a']++;
    for (int i = 0; i < k; i++)
        c[cc[i] - 'a']++;
    for (int i = 0; i < n; i++){
        bool flag = true;
        for (int j = 0; j < 26; j++){
            if (a[j] < b[j] * i)
                flag = false;
            a[j] -= b[j] * i;
        }
        if (flag){
            int ma = 100000000;
            for (int j = 0; j < 26; j++)
                if (c[j] != 0)
                    ma = min(ma, a[j] / c[j]);
            if (ma + i > ans)
                ans = ma + i, e = i;
        }
        for (int j = 0; j < 26; j++)
            a[j] += b[j] * i;
    }
    for (int i = 0; i < e; i++)
        cout << bb;
    for (int i = 0; i < ans - e; i++)
        cout << cc;
    for (int i = 0; i < 26; i++){
        a[i] -= c[i] * (ans - e) + b[i] * e;
        for (int j = 0; j < a[i]; j++)
            printf("%c",char(i + 'a'));
    }
    return 0;
}
