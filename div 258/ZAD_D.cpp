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
const double EPS = 1E-10;
const ll inf = 2000000010;
using namespace std;
ll ac[100010],bc[100010],an[100010],bn[100010];
string s;
int main ()
    {
        cin >> s;
        ll n = s.length(),i,ct = 0,nt = 0;
        ac[0] = 0;
        bc[0] = 0;
        an[0] = 0;
        bn[0] = 0;
        for (i=1;i<=n;i++)
            {
                ac[i] = ac[i-1];
                bc[i] = bc[i-1];
                an[i] = an[i-1];
                bn[i] = bn[i-1];
                if (s[i-1] == 'a')
                    {
                        if (i%2) an[i]++;
                        else ac[i]++;
                    }
                else
                    {
                        if (i%2) bn[i]++;
                        else bc[i]++;
                    }
            }
        for (i=1;i<=n;i++)
            {
                if (s[i-1] == 'a')
                    {
                        if (i%2)
                            {
                                nt+=(n-i+2)/2-bn[n]+bn[i-1];
                                ct+=(n-i+1)/2-bc[n]+bc[i-1];
                            }
                        else
                            {
                                nt+=(n-i+2)/2-bc[n]+bc[i-1];
                                ct+=(n-i+1)/2-bn[n]+bn[i-1];
                            }
                    }
                else
                    {
                        if (i%2)
                            {
                                nt+=(n-i+2)/2-an[n]+an[i-1];
                                ct+=(n-i+1)/2-ac[n]+ac[i-1];
                            }
                        else
                            {
                                nt+=(n-i+2)/2-ac[n]+ac[i-1];
                                ct+=(n-i+1)/2-an[n]+an[i-1];
                            }
                    }
            }
        cout << ct << ' ' << nt << endl;
        return 0;
    }
