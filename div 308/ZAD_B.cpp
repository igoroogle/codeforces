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
int main ()
    {
        ll s = 0,k = 1,t = 10, t1 = 1,n;
        cin >> n;
        while (t <= n)
            {
                s+=k*(t-t1);
                t1 = t;
                t*=10;
                k++;
            }
        s+=(n-t1+1)*k;
        cout << s << endl;
        return 0;
    }
