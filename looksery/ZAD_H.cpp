#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <stack>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef double ld;

const
    int INF = 2147483646;
    double EPS = 0.00000000000001;
    double PI = 3.14159265358979310000;

ld a, b, c, d;

bool prov(ld x)
{
    ld aa, bb, cc, dd, a1, a2, b1, b2, c1, c2, d1, d2, W,uio;

    a1 = a + x;
    a2 = a - x;
    b1 = b + x;
    b2 = b - x;
    c1 = c + x;
    c2 = c - x;
    d1 = d + x;
    d2 = d - x;

    //===
    if (abs(((b1 * c1) / a1) - d) <= x)
        return 1;

    if (abs(((b1 * c2) / a1) - d) <= x)
        return 1;

    if (abs(((b2 * c1) / a1) - d) <= x)
        return 1;

    if (abs(((b2 * c2) / a1) - d) <= x)
        return 1;

    //===

    if (abs(((b1 * c1) / a2) - d) <= x)
        return 1;

    if (abs(((b1 * c2) / a2) - d) <= x)
        return 1;

    if (abs(((b2 * c1) / a2) - d) <= x)
        return 1;

    if (abs(((b2 * c2) / a2) - d) <= x)
        return 1;


    //============d
    //===
    if (abs(((b1 * c1) / d1) - a) <= x)
        return 1;

    if (abs(((b1 * c2) / d1) - a) <= x)
        return 1;

    if (abs(((b2 * c1) / d1) - a) <= x)
        return 1;

    if (abs(((b2 * c2) / d1) - a) <= x)
        return 1;

    //===

    if (abs(((b1 * c1) / d2) - a) <= x)
        return 1;

    if (abs(((b1 * c2) / d2) - a) <= x)
        return 1;

    if (abs(((b2 * c1) / d2) - a) <= x)
        return 1;

    if (abs(((b2 * c2) / d2) - a) <= x)
        return 1;


    //======================================

    //===
    if (abs(((a1 * d1) / b1) - c) <= x)
        return 1;

    if (abs(((a1 * d2) / b1) - c) <= x)
        return 1;

    if (abs(((a2 * d1) / b1) - c) <= x)
        return 1;

    if (abs(((a2 * d2) / b1) - c) <= x)
        return 1;

    //===

    if (abs(((a1 * d1) / b2) - c) <= x)
        return 1;

    if (abs(((a1 * d2) / b2) - c) <= x)
        return 1;

    if (abs(((a2 * d1) / b2) - c) <= x)
        return 1;

    if (abs(((a2 * d2) / b2) - c) <= x)
        return 1;

    //======================================

    //===
    if (abs(((a1 * d1) / c1) - b) <= x)
        return 1;

    if (abs(((a1 * d2) / c1) - b) <= x)
        return 1;

    if (abs(((a2 * d1) / c1) - b) <= x)
        return 1;

    if (abs(((a2 * d2) / c1) - b) <= x)
        return 1;

    //===

    if (abs(((a1 * d1) / c2) - b) <= x)
        return 1;

    if (abs(((a1 * d2) / c2) - b) <= x)
        return 1;

    if (abs(((a2 * d1) / c2) - b) <= x)
        return 1;

    if (abs(((a2 * d2) / c2) - b) <= x)
        return 1;

    return 0;
}

int main()
{
    ld l, r, m, q;
    q = 0;
    cin >> a >> b >> c >> d;
    l = 0.0;
    r = 10000001000.0;
    for (int bin = 0; bin < 100000; bin++)
    {
        m = (l + r) / 2;

        if (prov(m))
            r = m;
        else
            l = m;

    }
    cout << fixed << setprecision(18) << r;

  return 0;
}

