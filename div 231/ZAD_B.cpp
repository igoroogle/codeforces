#include <string>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
char s[1000002], s1[1000002];
int main()
{
    int p, x, i, j, ost, val;
    cin >> p >> x;
    for (i = 0; i < 1000002; i++)
    {
        s[i] = '\0';
        s1[i] = '\0';
    }
    s[0] = '$';
    for (j = 0; j <= 9; j++)
    {
        val = j;
        ost = 0;
        s1[0] = '$';
        for (i = 0; i < p; i++)
        {
            s1[i] = char(val + '0');
            val = val * x + ost;
            if (val > 99)
            {
                s1[0] = '$';
                break;
            }
            ost = val / 10;
            val = val % 10;
        }
        reverse(s1, s1 + p);
        if ((s1[0] != '$') && (s1[0] != '0') && (ost == 0) && (val == j) && ((s[0] == '$') || (s1 < s)))
            for (i = 0; i < p; i++)
                s[i] = s1[i];
    }
    if (s[0] == '$')
        cout << "Impossible\n";
    else
        {
            for (i = 0; i < p; i++)
                printf("%c", s[i]);
        }
    return 0;
}
