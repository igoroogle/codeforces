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
string a,b,c,k = "";
int a1[27],b1[27],c1[27],tr[27];
int main ()
    {
        cin >> a >> b >> c;
        int i,kol1 = 0,kol2 = 0;
        for (i=0;i<27;i++)
            {
                a1[i] = 0;
                b1[i] = 0;
                c1[i] = 0;
            }
        for (i=0;i<a.length();i++) a1[int(a[i]-'a')]++;
        for (i=0;i<b.length();i++) b1[int(b[i]-'a')]++;
        for (i=0;i<c.length();i++) c1[int(c[i]-'a')]++;
        for (i=0;i<27;i++) tr[i] = a1[i];
        int k1 = 1000000;
        for (i=0;i<27;i++)
            {
                if (b1[i] > 0)
                    {
                        if (b1[i] <= a1[i]) k1 = min(k1,a1[i] / b1[i]);
                        else k1 = 0;
                    }
            }
        for (i=0;i<27;i++) a1[i]-=b1[i]*k1;
        int k2 = 1000000;
        for (i=0;i<27;i++)
            {
                if (c1[i] > 0)
                    {
                        if (c1[i] <= a1[i]) k2 = min(k2,a1[i] / c1[i]);
                        else k2 = 0;
                    }
            }
        for (i=0;i<27;i++) a1[i]-=c1[i]*k2;
        kol1 = k1;
        kol2 = k2;
        bool f = 1;
        int mx = k1+k2,km1 = k1,km2 = k2;
        while (kol1>0)
            {
                for (i=0;i<27;i++) a1[i]+=b1[i];
                k2 = 1000000;
                for (i=0;i<27;i++)
                    {
                        if (c1[i] > 0)
                            {
                                if (c1[i] <= a1[i]) k2 = min(k2,a1[i] / c1[i]);
                                else k2 = 0;
                            }
                    }
                    kol1--;
                    kol2+=k2;
                    for (i=0;i<27;i++) a1[i]-=c1[i]*k2;
                    if (kol1+kol2 > mx)
                        {
                            km1 = kol1;
                            km2 = kol2;
                            mx = kol1 + kol2;
                        }
            }
        for (i=0;i<km1;i++) k+=b;
        for (i=0;i<km2;i++) k+=c;
        for (i=0;i<27;i++) a1[i] = tr[i];
        for (i=0;i<27;i++)
            {
                a1[i]-=b1[i]*km1;
                a1[i]-=c1[i]*km2;
            }
        int j;
        for (i=0;i<27;i++)
            for (j=0;j<a1[i];j++) k+=char(i+'a');
        cout << k << endl;
        return 0;
    }
