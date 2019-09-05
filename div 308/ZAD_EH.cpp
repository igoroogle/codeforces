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
string s;
ll d[2502][2502],d1[2502][2502],u[2502][2502],u1[2502][2502];
int main ()
    {
        cin >> s;
        ll tr,an,n = s.length(),i,j;
        for (i=0;i<n;i+=2)
            {
                tr = 0;
                an = s[i] - '0';
                d[i/2][i/2] = tr;
                d1[i/2][i/2] = an;
                for (j=i;j<n-2;j+=2)
                    {
                        if (s[j+1] == '+')
                            {
                                tr+=an;
                                an = ll(s[j+2] - '0');
                                d[i/2][(j+2)/2] = tr;
                                d1[i/2][(j+2)/2] = an;
                            }
                        else
                            {
                                an*=ll(s[j+2] - '0');
                                d[i/2][(j+2)/2] = tr;
                                d1[i/2][(j+2)/2] = an;
                            }
                    }
            }
        for (i=n-1;i>=0;i-=2)
            {
                tr = 0;
                an = s[i] - '0';
                u[i/2][i/2] = tr;
                u1[i/2][i/2] = an;
                for (j=i;j>=2;j-=2)
                    {
                        if (s[j-1] == '+')
                            {
                                tr+=an;
                                an = ll(s[j-2] - '0');
                                u[(j-2)/2][i/2] = tr;
                                u1[(j-2)/2][i/2] = an;
                            }
                        else
                            {
                                an*=ll(s[j-2] - '0');
                                u[(j-2)/2][i/2] = tr;
                                u1[(j-2)/2][i/2] = an;
                            }
                    }
            }
        ll ss = 0,t;
        for (i=0;i<n;i+=2)
            for (j=i;j<n;j+=2)
                {
                    t = d[i/2][j/2]+d1[i/2][j/2];
                    if ( (i-1 >= 0) && (s[i-1] == '+') )
                        {
                            if (j+1 < n)
                                {
                                    if (s[j+1] == '+') t+=d1[(j+2)/2][(n-1)/2];
                                    else if (s[j+1] == '*') t*=u1[(j+2)/2][(n-1)/2];
                                }
                            t+=d1[0][(i-2)/2];
                        }
                    else
                        {
                            if (i-1 >= 0) t*=d1[0][(i-2)/2];
                            if (j+1 < n)
                                {
                                    if (s[j+1] == '+') t+=d1[(j+2)/2][(n-1)/2];
                                    else if (s[j+1] == '*') t*=u1[(j+2)/2][(n-1)/2];
                                }
                        }
                    if (i-1 >=0) t+=d[0][(i-2)/2];
                    if (j+1 < n) t+=u[(j+2)/2][(n-1)/2];
                    if (t > ss) ss = t;
                }
        cout << ss << endl;
        return 0;
    }
