#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

const ll INF = 99999999999999;
ll a, b, sum;
double x;

int main()
{
    cin >> a >> b;

    if (b > a)
    {
        cout << -1;
        return 0;
    }

    sum = (a - b) / (b * 2.0);

    x = INF;

    if (sum > 0)
        x = (a - b) / double(sum * 2.0);

    sum = (a + b) / (b * 2);

    if (sum > 0)
        x = min(x, (a + b) / double(sum * 2.0));


    if (x < INF)
        cout << setprecision(11) << fixed << x << endl;
    else
        cout << -1 << endl;

    return 0;
}
