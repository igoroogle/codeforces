#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979310000;
using namespace std;
int a[210][210],b[210];
int f (int k,int x)
    {
        int t;
        if (a[k][x] != -1) return a[k][x];
        a[k][x] = 2000000000;
        if (k == 1)
            {
                a[k][x] = b[x-1];
                return b[x-1];
            }
        t = f(k-1,x);
        if (t < 2000000000) a[k][x] = b[t-1];
        else a[k][x] = 2000000000;
        return a[k][x];
    }
int main ()
    {
        int i,j,n,mk,s;
        for (i=0;i<210;i++)
            for (j=0;j<210;j++) a[i][j] = -1;
        mk = 2000000000;
        cin >> n;
        for (i=0;i<n;i++) cin >> b[i];
        for (i=0;i<n;i++)
            {
                s = 0;
                for (j=0;j<n;j++)
                    if (f(i+1,f(i+1,j+1)) == f(i+1,j+1)) s++;
                if ( (s == n) && (i+1 < mk) ) mk = i+1;
            }
        cout << mk;
        return 0;
    }
