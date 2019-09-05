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
ll a[600010];
string s;
int n;
bool binp(ll);
int main ()
    {
        int m,i,j;
        ll st = 1,ss,sk;
        bool f;
        cin >> n >> m;
        for (i=0;i<n;i++)
            {
                cin >> s;
                st = 1;
                a[i] = 0;
                for (j=0;j<s.length();j++)
                    {
                        if (s[j] == 'a') a[i]+=st;
                        else if (s[j] == 'b') a[i]+=st*2;
                        else if(s[j] == 'c') a[i]+=st*3;
                        st*=3;
                    }
            }
        sort(a,a+n);
        for (i=0;i<m;i++)
            {
                cin >> s;
                st = 1;
                ss = 0;
                for (j=0;j<s.length();j++)
                    {
                        if (s[j] == 'a') ss+=st;
                        else if (s[j] == 'b') ss+=st*2;
                        else if (s[j] == 'c') ss+=st*3;
                        st*=3;
                    }
                f = 1;
                st = 1;
                for (j=0;j<s.length();j++)
                    {
                        if (s[j] != 'a')
                            {
                                sk = ss - st*ll(s[j]-'a'+1)+st;
                                if (binp(sk))
                                    {
                                        printf("YES\n");
                                        f = 0;
                                        break;
                                    }
                                sk = ss;
                            }
                        if (s[j] != 'b')
                            {
                                sk = ss - st*ll(s[j]-'a'+1)+st*2;
                                if (binp(sk) )
                                    {
                                        printf("YES\n");
                                        f = 0;
                                        break;
                                    }
                                sk = ss;
                            }
                        if (s[j] != 'c')
                            {
                                sk = ss - st*ll(s[j]-'a'+1)+st*3;
                                if (binp(sk))
                                    {
                                        printf("YES\n");
                                        f = 0;
                                        break;
                                    }
                                sk = ss;
                            }
                        st*=3;
                    }
                if (f) printf("NO\n");
            }
        return 0;
    }
bool binp (ll s)
    {
        int l,r,m;
        l = 0;
        r = n-1;
        while (l < r)
            {
               m = (l+r) / 2;
               if (a[m] < s) l = m+1;
               else r = m;
            }
        return s == a[l];
    }
