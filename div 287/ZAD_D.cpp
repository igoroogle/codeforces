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
ll pw[1010],n,k,m;
ll rec(ll,ll);
int main ()
    {
        ll i,ans = 0,z,t,f;
        cin >> n >> k >> m;
        pw[0] = 1 % m;
        for (i=1;i<1010;i++) pw[i] = (pw[i-1]*10)%m;
        cout << rec(n,0) << endl;
        return 0;
    }
ll rec(ll nn,ll pr)
    {
        if (nn == 0) return 0;
        else
            {
                ll i,f = 0,s = 0;
                if (nn == n) f = 1;
                for (i=f;i<=9;i++)
                    {
                        if ((pr*10+i)%k) s=(s+rec(nn-1,(pr*10+i)%k) ) % m;
                        else s = (s + pw[nn-1]) % k;
                    }
                return s;
            }
    }
