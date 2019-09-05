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
ll rec(ll);
ll a[100010];
int main ()
    {
        ll n,m,k,i,j,x,y;
        cin >> n >> k;
        for (i=0;i<k;i++)
            {
                scanf("%I64d",&m);
                x = -1;
                for (j=0;j<m;j++)
                    {
                        scanf("%I64d",&y);
                        y--;
                        a[y] = x;
                        x = y;
                    }
            }
        cout << rec(n-1) << endl;
        return 0;
    }
ll rec(ll n)
    {
        if (n == 0) return 0;
        else
            {
                ll g;
                g = rec(n-1);
                if (a[n] == -1) return 1 + g;
                else if (g == 0) return 0;
                else return 2 + g;
            }
    }
