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
using namespace std;
ll sm[1000100];
int main ()
    {
        ll n,r,avg,i,j,x,y,ss = 0,sk = 0;
        cin >> n >> r >> avg;
        for (i=0;i<1000100;i++) sm[i] = 0;
        for (i=0;i<n;i++)
            {
                scanf("%I64d%I64d",&x,&y);
                ss+=x;
                sm[y]+=r-x;
            }
        i = 0;
        while ( (ss/n < avg) && (i < 1000100) )
            {
                if (avg*n >= sm[i]+ss)
                    {
                        sk+=i*sm[i];
                        ss+=sm[i];
                    }
                else
                    {
                        sk += i*(avg*n-ss);
                        ss+=avg*n-ss;
                    }
                i++;
            }
        cout << sk << endl;
        return 0;
    }
