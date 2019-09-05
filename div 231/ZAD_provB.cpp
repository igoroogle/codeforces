#include <string>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
string s = "", s1;
int main()
{
    int p, x, i, j, ost, val;
    cin >> p >> x;
    for (j = 0; j <= 9; j++)
    {
        val = j;
        ost = 0;
        s1 = "";
        for (i = 0; i < p; i++)
        {
            s1 = char(val + '0') + s1;
            val = val * x + ost;
            if (val > 99)
            {
                s1 == "";
                break;
            }
            ost = val / 10;
            val = val % 10;
        }
        if ((s1 != "") && (s1[0] != '0') && (ost == 0) && (val == j) && ((s == "") || (s1 < s)))
            s = s1;
    }
    if (s == "")
        cout << "Impossible\n";
    else
        cout << s << endl;
    return 0;
}
