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
int main ()
    {
        ll a1,b1,a2,b2,a1d = 0,kt = 0,a1t = 0,b1d = 0,b1t = 0,a2d = 0,a2t = 0,b2d = 0,b2t = 0,h1,w1,h2,w2;
        cin >> a1 >> b1 >> a2 >> b2;
        h1 = a1;
        w1 = b1;
        h2 = a2;
        w2 = b2;
        while (!(h1%2))
            {
                a1d++;
                h1/=2;
            }
        while (!(h1%3))
            {
                a1t++;
                h1/=3;
            }
        while (!(w1%2))
            {
                b1d++;
                w1/=2;
            }
        while (!(w1%3))
            {
                b1t++;
                w1/=3;
            }while (!(h2%2))
            {
                a2d++;
                h2/=2;
            }
        while (!(h2%3))
            {
                a2t++;
                h2/=3;
            }while (!(w2%2))
            {
                b2d++;
                w2/=2;
            }
        while (!(w2%3))
            {
                b2t++;
                w2/=3;
            }
        if (h1*w1 != h2*w2)
            {
                cout << "-1\n";
                return 0;
            }
        while (min(a1t+b1t,a2t+b2t) > 0)
            {
                if (a1t > 0)
                    {
                        a1t--;
                        h1*=3;
                    }
                else
                    {
                        b1t--;
                        w1*=3;
                    }
                if (a2t > 0)
                    {
                        a2t--;
                        h2*=3;
                    }
                else
                    {
                        b2t--;
                        w2*=3;
                    }
            }
        kt+=a1t;
        a1d+=a1t;
        kt+=b1t;
        b1d+=b1t;
        kt+=a2t;
        a2d+=a2t;
        kt+=b2t;
        b2d+=b2t;
        while (min(a1d+b1d,a2d+b2d) > 0)
            {
                if (a1d > 0)
                    {
                        a1d--;
                        h1*=2;
                    }
                else
                    {
                        b1d--;
                        w1*=2;
                    }
                if (a2d > 0)
                    {
                        a2d--;
                        h2*=2;
                    }
                else
                    {
                        b2d--;
                        w2*=2;
                    }
            }
        kt+=a1d;
        kt+=b1d;
        kt+=a2d;
        kt+=b2d;
        cout << kt << endl << h1 << ' ' << w1 << endl << h2 << ' ' << w2 << endl;
        return 0;
    }
