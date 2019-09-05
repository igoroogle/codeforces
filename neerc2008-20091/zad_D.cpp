#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double a, b, c, x, y, r, res, dist;

int main()
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);

    cin >> a >> b >> c >> x >> y >> r;

    dist = abs(a * x + b * y + c) / sqrt(a * a + b * b);

    res = 2 * sqrt(r * r - dist * dist);

    if (dist > r)
        cout << 0;
    else
        printf("%.11lf\n", res);
    return 0;
}
