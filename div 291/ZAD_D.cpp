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
ll a[100010][6],b[6];
int main ()
    {
        ll n,m,k,i,j,x,l,r,mm,s,s2,mx = 0;
        cin >> n >> m >> k;
        for (i=0;i<6;i++) b[i] = 0;
        for (i=0;i<m;i++) a[0][i] = 0;
        for (i=1;i<=n;i++)
            for (j=0;j<m;j++)
            {
                scanf("%I64d",&x);
                a[i][j] = a[i-1][j] + x;
            }
        for (i=1;i<=n;i++)
            {
                l = i;
                r = n;
                while (l < r)
                    {
                        mm = (l+r) / 2;
                        s = 0;
                        for (j=0;j<m;j++) s+=a[mm][j] - a[i-1][j];
                        if (s < k) l = mm + 1;
                        else r = mm;
                    }
                s = 0;
                for (j=0;j<m;j++) s+=a[l][j] - a[i-1][j];
                s2 = -1;
                if (l-1 >=i)
                    {
                        s2 = 0;
                        for (j=0;j<m;j++) s2+=a[l-1][j] - a[i-1][j];
                    }
                if (s <= k)
                    {
                        if (l - i + 1 >mx)
                            {
                                mx = l - i + 1;
                                for (j=0;j<m;j++) b[j] = a[l][j] - a[i-1][j];
                            }
                    }
                else if (s2 != -1)
                    {
                        l--;
                        s = s2;
                        if (l - i + 1 >mx)
                            {
                                mx = l - i + 1;
                                for (j=0;j<m;j++) b[j] = a[l][j] - a[i-1][j];
                            }
                    }
            }
        for (i=0;i<m-1;i++) cout << b[i] << ' ';
        cout << b[m-1] << endl;
        return 0;
    }
