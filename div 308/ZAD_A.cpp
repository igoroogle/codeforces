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
ll a[110][110];
int main ()
    {
        int i,j,k,l,n,x1,x2,y1,y2;
        ll s = 0;
        cin >> n;
        for (i=0;i<100;i++)
            for (j=0;j<100;j++) a[i][j] = 0;
        for (i=0;i<n;i++)
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                if (x1 > x2) swap(x1,x2);
                if (y1 > y2) swap(y1,y2);
                for (k=x1-1;k<x2;k++)
                    for (l=y1-1;l<y2;l++)
                        a[k][l]++;
            }
        for (i=0;i<100;i++)
            for (j=0;j<100;j++)
                s+=a[i][j];
        cout << s << endl;
        return 0;
    }
