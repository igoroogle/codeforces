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
int a[100010],b[100010],c[100010];
int main ()
    {
        int n,i,k = 0,t = 0;
        cin >> n;
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        for (i=0;i<n-1;i++) scanf("%d",&b[i]);
        for (i=0;i<n-2;i++) scanf("%d",&c[i]);
        sort(a,a+n);
        sort(b,b+n-1);
        sort(c,c+n-2);
        for (i=0;i<n-1;i++)
            if (b[i] > a[i])
                {
                    k = a[i];
                    break;
                }
        if (k == 0) k = a[n-1];
        for (i=0;i<n-2;i++)
            if (c[i] > b[i])
                {
                    t = b[i];
                    break;
                }
        if (t == 0) t = b[n-2];
        cout << k << endl << t << endl;
        return 0;
    }
