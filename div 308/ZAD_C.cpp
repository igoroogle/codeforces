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
        ll m,w,i,t,k;
        for (i=0;i<110;i++) a[i] = 0;
        cin >> w >> m;
        k = 0;
        t = 1;
        while (m > 0)
            {
                if ( m % w == 1) a[k]++;
                else if (m % w == w-1)
                    {
                        a[k]++;
                        m+=t;
                    }
                else if (m % w > 0) a[k] = 110;
                m/=w;
                k++;
                t*=w;
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
