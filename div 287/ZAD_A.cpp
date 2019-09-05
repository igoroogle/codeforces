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
bool b[110];
ll ans[100010],a[100010];
int main ()
    {
        ll i,j,n,k,kl = 0,mx;
        cin >> n >> k;
        for (i=0;i<n;i++) scanf("%I64d",&a[i]);
        for (i=0;i<n;i++) b[i] = 1;
        for (i=0;i<10010;i++)
            {
                mx = -1;
                for (j=0;j<n;j++)
                    {
                        if ( (b[j]) && (a[j] <= k) && ((mx == -1) || (a[mx] > a[j])) ) mx = j;
                    }
                if (mx != -1)
                    {
                        b[mx] = 0;
                        kl++;
                        ans[kl-1] = mx;
                        k-=a[mx];
                    }
            }
        cout << kl << endl;
        for (i=0;i<kl;i++) printf("%I64d ",ans[i]+1);
    }
