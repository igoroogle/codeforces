#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <map>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
const ll md = 1000000007;
using namespace std;
ll a[6][20][100004],b[6],pw[20],ln[100010];
int main ()
    {
        ll n,m,k,i,j,p,x,l,r,mm,s,s2,mx = 0,sk;
        cin >> n >> m >> k;
        pw[0] = 1;
        for (i=1;i<20;i++) pw[i] = pw[i-1] + pw[i-1];
        s = 0;
        for (i=0;i<100010;i++)
            {
                if (pw[s+1] <= i) s++;
                ln[i] = s;
            }
        for (i=0;i<6;i++) b[i] = 0;
        for (i=0;i<n;i++)
            for (j=0;j<m;j++) scanf("%I64d",&a[j][0][i]);
            for (p=0;p<m;p++)
                for (i=1;i<20;i++)
                    for (j=0;j<n;j++)
                        {
                            a[p][i][j] = a[p][i-1][j];
                            if (j+pw[i-1] < n) a[p][i][j] = max(a[p][i-1][j],a[p][i-1][j+pw[i-1]]);
                        }
        for (i=0;i<n;i++)
            {
                l = i;
                r = n;
                while (l < r)
                    {
                        mm = (l+r) / 2;
                        s = 0;
                        for (j=0;j<m;j++)
                            {
                                sk = mm - i + 1;
                                p = ln[sk];
                                sk = pw[p];
                                s+=max(a[j][p][i],a[j][p][mm-sk+1]);
                            }
                        if (s <= k) l = mm + 1;
                        else r = mm;
                    }
                s = 0;
                for (j=0;j<m;j++)
                            {
                                sk = l - i + 1;
                                p = ln[sk];
                                sk = pw[p];
                                s+=max(a[j][p][i],a[j][p][l-sk+1]);
                            }
                s2 = -1;
                if (l-1 >=i)
                    {
                        s2 = 0;
                        for (j=0;j<m;j++)
                            {
                                sk = l - i + 1;
                                p = ln[sk];
                                sk = pw[p];
                                s2+=max(a[j][p][i],a[j][p][l-sk+1]);
                            }
                    }
                if (s <= k)
                    {
                        if (l - i + 1 >mx)
                            {
                                mx = l - i + 1;
                                for (j=0;j<m;j++)
                                    {
                                        sk = l - i + 1;
                                        p = ln[sk];
                                        sk = pw[p];
                                        b[j] = max(a[j][p][i],a[j][p][l-sk+1]);
                                    }
                            }
                    }
                else if (s2 != -1)
                    {
                        l--;
                        s = s2;
                        if (l - i + 1 >mx)
                            {
                                mx = l - i + 1;
                                for (j=0;j<m;j++)
                                    {
                                        sk = l - i + 1;
                                        p = ln[sk];
                                        sk = pw[p];
                                        b[j] = max(a[j][p][i],a[j][p][l-sk+1]);
                                    }
                            }
                    }
            }
        for (i=0;i<m-1;i++) cout << b[i] << ' ';
        cout << b[m-1] << endl;
        return 0;
    }
