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
ll d[5010][5010];
int main ()
    {
        cin >> s;
        ll tr,an,n = s.length(),i,j;
        for (i=0;i<n;i+=2)
            {
                tr = 0;
                an = s[i] - '0';
                d[i][i] = an;
                for (j=i;j<n-2;j+=2)
                    {
                        if (s[j+1] == '+')
                            {
                                tr+=an;
                                an = ll(s[j+2] - '0');
                                d[i][j+2] = tr + an;
                            }
                        else
                            {
                                an*=ll(s[j+2] - '0');
                                d[i][j+2] = tr + an;
                            }
                    }
            }
        ll ss = 0,t,xx = 0,yy = 0;
        for (i=0;i<n;i+=2)
            for (j=i;j<n;j+=2)
                {
                    t = d[i][j];
                    if ( (i-1 >= 0) && (s[i-1] == '+') )
                        {
                            if (j+1 < n)
                                {
                                    if (s[j+1] == '+') t+=d[j+2][n-1];
                                    else if (s[j+1] == '*') t*=d[j+2][n-1];
                                }
                            t+=d[0][i-2];
                        }
                    else
                        {
                            if (i-1 >= 0) t*=d[0][i-2];
                            if ((i == 4) && (j == 6)) cout << t << endl;
                            if (j+1 < n)
                                {
                                    if (s[j+1] == '+') t+=d[j+2][n-1];
                                    else if (s[j+1] == '*') t*=d[j+2][n-1];
                                }
                        }
                    if (t > ss)
                        {
                            ss = t;
                            xx = i;
                            yy = j;
                        }
                }
        cout << ss << ' ' << xx << ' ' << yy << endl;
        cin >> xx >> yy;
        cout << d[xx][yy] << endl;
        return 0;
    }
