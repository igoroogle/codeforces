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
string a[100010],b[100010];
int main ()
    {
        ll n,i,j,f;
        a[0] = "";
        cin >> n;
        for (i=1;i<=n;i++)
            {
                cin >> a[i];
                b[i] = a[i];
                if (a[i].length() < a[i-1].length())
                    {
                        cout << "NO\n";
                        return 0;
                    }
                else if (a[i].length() > a[i-1].length())
                    {
                        if (a[i][0] == '?') a[i][0] = '1';
                        for (j=1;j<a[i].length();j++)
                            if (a[i][j] == '?') a[i][j] = '0';
                    }
                else
                    {
                        f = 0;
                        for (j=0;j<a[i].length();j++)
                            if ( (a[i][j] != '?') && (a[i][j] != a[i-1][j]) )
                                {
                                    if (a[i-1][j] < a[i][j]) f = - (j+1);
                                    else f = j + 1;
                                    break;
                                }
                        if (f > 0)
                            {
                                for (j=f-1;j>=0;j--)
                                    if (a[i][j] == '?')
                                        {
                                            if (a[i-1][j] == '9') a[i][j] = '9';
                                            else
                                                {
                                                    a[i][j] = a[i-1][j] + 1;
                                                    f = - (j+1);
                                                    break;
                                                }
                                        }
                            }
                        if (f < 0)
                            {
                                for (j=0;j<-f-1;j++) a[i][j] = a[i-1][j];
                                for (j=-f;j<a[i].length();j++)
                                    if (a[i][j] == '?') a[i][j] = '0';
                            }
                        if (f == 0)
                            {
                                f = -1;
                                for (j=a[i].length()-1;j>=0;j--)
                                    if (a[i][j] == '?')
                                        {
                                            if (a[i-1][j] == '9') a[i][j] = '9';
                                            else
                                                {
                                                    a[i][j] = a[i-1][j]+1;
                                                    f = j;
                                                    break;
                                                }
                                        }
                                for (j=0;j<f;j++) a[i][j] = a[i-1][j];
                            }
                        if ( (a[i].length() == a[i-1].length()) && (a[i] <= a[i-1]) )
                            {
                                cout << "NO\n";
                                if (n == 1000)
                                    {
                                        cout << a[i-2] << endl;
                                        cout << a[i-1] << endl;
                                        cout << a[i] << endl;
                                        cout << b[i-2] << endl;
                                        cout << b[i-1] << endl;
                                        cout << b[i] << endl;
                                    }
                                return 0;
                            }
                    }
            }
        cout << "YES\n";
        for (i=1;i<=n;i++) cout << a[i] << endl;
        return 0;
    }
