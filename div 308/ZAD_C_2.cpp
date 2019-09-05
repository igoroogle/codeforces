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
int a[110];
int main ()
    {
        ll m,w,i,t,k,ost = 0;
        for (i=0;i<110;i++) a[i] = 0;
        cin >> w >> m;
        k = 0;
        t = 1;
        while (m + ost > 0)
            {
                if ( (ost > 0) && (m % w == w-1) ) ost = 1;
                else if ( m % w + ost == 1)
                    {
                        a[k]++;
                        ost = 0;
                    }
                else if (m % w + ost == w-1)
                    {
                        a[k]++;
                        ost = 1;
                    }
                else if (m % w + ost > 0) a[k] = 110;
                m/=w;
                k++;
            }
        for (i=0;i<110;i++)
            if (a[i] > 1)
                {
                    cout << "NO" << endl;
                    return 0;
                }
        cout << "YES" << endl;
        return 0;
    }
