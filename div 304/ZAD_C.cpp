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
const double PI = 3.14159265358979311600;
using namespace std;
int b1[14],b2[14];
int main ()
    {
        bool f = 1;
        int l1 = 0,r1 = 0,l2 = 0,r2 = 0,k1,k2,n,i,j,k,l,rn = 0,t;
        cin >> n;
        cin >> k1;
        for (i=0;i<k1;i++) scanf("%d",&b1[i]);
        cin >> k2;
        for (i=0;i<k2;i++) scanf("%d",&b2[i]);
        l1 = 0;
        r1 = k1-1;
        l2 = 0;
        r2 = k2-1;
        for(i=0;i<39916810;i++)
            {
                if ( (k1 == 0) || (k2 == 0) )
                {
                   f = 0;
                   break;
                }
                rn++;
                if (b1[l1] > b2[l1])
                    {
                        r1++;
                        if (r1 == 14) r1 = 0;
                        b1[r1] = b2[l2];
                        r1++;
                        if (r1  == 14) r1 = 0;
                        b1[r1] = b1[l1];
                        l1++;
                        if (l1 == 14) l1 = 0;
                        l2++;
                        if (l2 == 14) l2 = 0;
                        k1++;
                        k2--;
                    }
                else
                    {
                        r2++;
                        if (r2 == 14) r2 = 0;
                        b2[r2] = b1[l1];
                        r2++;
                        if (r2 == 14) r2 = 0;
                        b2[r2] = b2[l2];
                        l1++;
                        if (l1 == 14) l1 = 0;
                        l2++;
                        if (l2 == 14) l2 = 0;
                        k1--;
                        k2++;
                    }
            }
        if (f) cout << -1 << endl;
        else
            {
                if (k1 == 0) t = 2;
                else t = 1;
                cout << rn << ' ' << t << endl;
            }
        return 0;
    }
