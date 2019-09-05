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
int a[3010];
int main ()
    {
        int i,n,s = 0;
        cin >> n;
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for (i=1;i<n;i++)
            if (a[i] <= a[i-1])
                {
                    s+=a[i-1] - a[i] + 1;
                    a[i] = a[i-1] + 1;
                }
        cout << s << endl;
        return 0;
    }
