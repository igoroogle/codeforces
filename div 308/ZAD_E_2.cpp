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
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
using namespace std;
string s;
ll d[5012],d1[5012],u[5012],u1[5012],ss = 0,n;
void get(ll,ll,ll);
int main ()
    {
        cin >> s;
        n = s.length();
        ll tr,an,i,j;
        tr = 0;
        an = ll(s[0] - '0');
        d[0] = tr;
        d1[0] = an;
        for (i=0;i<n-2;i+=2)
            {
                if (s[i+1] == '+')
                    {
                        tr+=an;
                        an = ll(s[i+2] - '0');
                        d[i+2] = tr;
                        d1[i+2] = an;
                    }
                else
                    {
                        an*=ll(s[i+2] - '0');
                        d[i+2] = tr;
                        d1[i+2] = an;
                    }
            }
        tr = 0;
        an = ll(s[n-1] - '0');
        u[n-1] = tr;
        u1[n-1] = an;
        for (i=n-1;i>=2;i-=2)
            {
                if (s[i-1] == '+')
                    {
                        tr+=an;
                        an = ll(s[i-2] - '0');
                        u[i-2] = tr;
                        u1[i-2] = an;
                    }
                else
                    {
                        an*=ll(s[i-2] - '0');
                        u[i-2] = tr;
                        u1[i-2] = an;
                    }
            }
        for (i=0;i<n;i+=2)
            {
                tr = 0;
                an = ll(s[i] - '0');
                get(tr+an,i,j);
                for (j=i;j<n-2;j+=2)
                    {
                        if (s[j+1] == '+')
                            {
                                tr+=an;
                                an = ll(s[j+2] - '0');
                            }
                        else an*=ll(s[j+2] - '0');
                        get(tr+an,i,j+2);
                    }
            }
        cout << ss << endl;
        return 0;
    }
void get(ll sk,ll f,ll l)
    {
        ll t = sk;
        if ( (f - 1 >=0) && (s[f-1] == '+') )
            {
                if (l+1 < n)
                   {
                       if (s[l+1] == '*') t*=u1[l+2];
                       else t+=u1[l+2];
                   }
                t+=d1[f-2];
            }
        else
            {
                if (f - 1 >=0) t*=d1[f-2];
                if (l+1 < n)
                   {
                       if (s[l+1] == '*') t*=u1[l+2];
                       else t+=u1[l+2];
                   }
            }
        if (f - 1 >=0) t+=d[f-2];
        if (l + 1 < n) t+=u[l+2];
        if (t > ss) ss = t;
    }
