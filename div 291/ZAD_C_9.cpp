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
map <ll,bool> a;
ll pw[63];
string s;
ll n;
int main ()
    {
        ll m,i,j,mdk,st,ss,sk;
        bool f;
        pw[0] = 1;
        for (i=1;i<63;i++) pw[i] = pw[i-1]*2;
        srand(time(0));
        mdk = pw[60] + rand() % (pw[61] - pw[60] + 1);
        //mdk = pw[57];
        cin >> n >> m;
        for (i=0;i<n;i++)
            {
                st = 1;
                cin >> s;
                ss = 0;
                for (j=0;j<s.length();j++)
                    {
                        ss = (ss+(st* ll(s[j] - 'a' + 1))% mdk) % mdk;
                        st = (st * 5) % mdk;
                    }
                a[ss] = 1;
            }
        for (i=0;i<m;i++)
            {
                cin >> s;
                ss = 0;
                st = 1;
                for (j=0;j<s.length();j++)
                    {
                        ss = (ss+(st* ll(s[j] - 'a' + 1))% mdk) % mdk;
                        st = (st * 5) % mdk;
                    }
                st = 1;
                f = 1;
                for (j=0;j<s.length();j++)
                    {
                        if (s[j] != 'a')
                            {
                               sk = ((ss + mdk - ((st* ll(s[j] - 'a' + 1))%mdk))%mdk + st)  % mdk;
                               if (a[sk])
                                    {
                                        printf("YES\n");
                                        f  = 0;
                                        break;
                                    }
                            }
                        if (s[j] != 'b')
                            {
                               sk = ((ss + mdk - ((st* ll(s[j] - 'a' + 1))%mdk)) % mdk + ( (st*2) % mdk) )  % mdk;
                               if (a[sk])
                                    {
                                        printf("YES\n");
                                        f  = 0;
                                        break;
                                    }
                            }
                        if (s[j] != 'c')
                            {
                               sk = ((ss + mdk - ((st* ll(s[j] - 'a' + 1))%mdk))%mdk + ( (st*3) % mdk) )  % mdk;
                               if (a[sk])
                                    {
                                        printf("YES\n");
                                        f  = 0;
                                        break;
                                    }
                            }
                        st = (st * 5) % mdk;
                    }
                if (f) printf("NO\n");
            }
        return 0;
    }
