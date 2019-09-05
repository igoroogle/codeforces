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
const int dl = 5000010;
using namespace std;
int b[dl];
ll sm[dl];
int main ()
    {
        int i,p,t,a1,b1;
        for (i=0;i<dl;i++)
            {
                if (i%2) b[i] = i;
                else b[i] = 2;
            }
        b[0] = 0;
        p = 3;
        while (p<dl)
            {
                if (b[p] == p)
                    {
                        for (i=p+p;i<dl;i+=p)
                            if (b[i] == i) b[i] = p;
                    }
                p+=2;
            }
        sm[0] = 0;
        sm[1] = 0;
        for (i=2;i<dl;i++) sm[i] = sm[i/b[i]] - sm[i/b[i] - 1] + 1 + sm[i-1];
        cin >> t;
        for (i=0;i<t;i++)
            {
                scanf("%d%d",&a1,&b1);
                printf("%I64d\n",sm[a1]-sm[b1]);
            }
        return 0;
    }
