#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char ans[1000010];
int main()
{
    ll a00, a01, a10, a11, ed = 0, nl = 0, an, n, fr = 0, sc = 0;
    cin >> a00 >>  a01 >> a10 >> a11;

    if (a00 + a01 + a10 + a11 == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    if ((a11 > 0) || (a01 > 0) || (a10 > 0))
        ed = 1;
    an = 0;
    while (an < a11)
    {
        an += ed;
        ed++;
    }

    if (an != a11)
    {
        cout << "Impossible\n";
        return 0;
    }

    if ((a00 > 0) || (a01 > 0) || (a10 > 0))
        nl = 1;
    an = 0;
    while (an < a00)
    {
        an += nl;
        nl++;
    }

    if (an != a00)
    {
        cout << "Impossible\n";
        return 0;
    }

    n = nl + ed;
    ans[n] = '\0';
    for (int i = 0; i < n; i++)
    {

        if ((ed + fr <= a01) && (nl > 0))
        {
            fr += ed;
            nl--;
            ans[i] = '0';
            continue;
        }

        if ((nl + sc <= a10) && (ed > 0))
        {
            sc += nl;
            ed--;
            ans[i] = '1';
            continue;
        }

        cout << "Impossible\n";
        return 0;
    }

    if ((fr != a01) || (sc != a10))
    {
        cout << "Impossible\n";
        return 0;
    }

    printf("%s\n", ans);

    return 0;
}
