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
#include <map>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
const ll md = 1000000007;
using namespace std;
ll pw[51];
ll rec(ll,ll,ll);
int main ()
    {
        ll i,n,h;
        pw[0] = 1;
        for (i=1;i<51;i++) pw[i] = pw[i-1]*2;
        cin >> h >> n;
        cout << rec(h,n,0) << endl;
        return 0;
    }
ll rec(ll h,ll n,ll vl)
    {
        if (h == 0)   return 0;
        else
            {
                if (vl == 0)
                    {
                        if (n > pw[h-1]) return pw[h]+rec(h-1,n-pw[h-1],0);
                        else return 1+rec(h-1,n,1);
                    }
                else
                    {
                        if (n > pw[h-1]) return 1+rec(h-1,n-pw[h-1],0);
                        else return pw[h]+rec(h-1,n,1);
                    }
            }
    }
