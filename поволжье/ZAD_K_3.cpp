#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 100010;
const int INF = 2000000000;
string s, s1;
int main()
{
    int n, i, j, z, p, ind, val1 = 0, val2 = 0, val3 = 0, z1, p1, z2, p2, ind0;
    bool f;
    cin >> n >> s;
    s1 = s;
    for (i = 0; i < n; i++)
        if (s[i] == 'F')
        {
            z = i;
            break;
        }

    for (i = n - 1; i >= 0; i--)
        if (s[i] == 'A')
        {
            p = i;
            break;
        }

    while (z < p)
    {
        while (s[z + 1] == 'N')
        {
            val1++;
            swap(s[z], s[z + 1]);
            z++;
        }

        while (s[p - 1] == 'N')
        {
            val1++;
            swap(s[p], s[p - 1]);
            p--;
        }
        for (i = z; i <= p; i++)
            if (s[i] == 'A')
            {
                ind = i;
                break;
            }
        for (i = ind - 1; i >= z; i--)
        {
            val1++;
            swap(s[i], s[i + 1]);
        }
        for (i = 0; i < n; i++)
        if (s[i] == 'F')
        {
            z = i;
            break;
        }

    for (i = n - 1; i >= 0; i--)
        if (s[i] == 'A')
        {
            p = i;
            break;
        }
    }

    s = s1;
    z1 = z;
    p1 = p;
    for (i = 0; i < n; i++)
        if (s[i] == 'F')
        {
            z = i;
            break;
        }

    for (i = n - 1; i >= 0; i--)
        if (s[i] == 'A')
        {
            p = i;
            break;
        }
    while (z < p)
    {

        while (s[z + 1] == 'N')
        {
            val2++;
            swap(s[z], s[z + 1]);
            z++;
        }

        while (s[p - 1] == 'N')
        {
            val2++;
            swap(s[p], s[p - 1]);
            p--;
        }

        for (i = p; i >= z; i--)
            if (s[i] == 'F')
            {
                ind = i;
                break;
            }

        for (i = ind + 1; i <= p; i++)
        {
            val2++;
            swap(s[i - 1], s[i]);
        }


        for (i = 0; i < n; i++)
        if (s[i] == 'F')
        {
            z = i;
            break;
        }

    for (i = n - 1; i >= 0; i--)
        if (s[i] == 'A')
        {
            p = i;
            break;
        }
    }
    z2 = z;
    p2 = p;
    s = s1;
    for (i = 0; i < n; i++)
        if (s[i] == 'F')
        {
            z = i;
            break;
        }

    for (i = n - 1; i >= 0; i--)
        if (s[i] == 'A')
        {
            p = i;
            break;
        }
    while (z < p)
    {
        while (s[z + 1] == 'N')
        {
            val3++;
            swap(s[z], s[z + 1]);
            z++;
        }

        while (s[p - 1] == 'N')
        {
            val3++;
            swap(s[p], s[p - 1]);
            p--;
        }
        for (i = z; i <= p; i++)
            if (s[i] == 'A')
            {
                ind = i;
                break;
            }

        for (i = p; i >= z; i--)
            if (s[i] == 'F')
            {
                ind0 = i;
                break;
            }

        if (ind - z > p - ind)
        {
        for (i = ind - 1; i >= z; i--)
        {
            val3++;
            swap(s[i], s[i + 1]);
        }
        }
        else
        {
        for (i = ind0 + 1; i <= p; i++)
        {
            val3++;
            swap(s[i - 1], s[i]);
        }
        }
        for (i = 0; i < n; i++)
        if (s[i] == 'F')
        {
            z = i;
            break;
        }

    for (i = n - 1; i >= 0; i--)
        if (s[i] == 'A')
        {
            p = i;
            break;
        }
    }
    /*val1 += z1 - p1 - 1;
    val2 += z2 - p2 - 1;*/
    val3 += z - p - 1;
    cout << val3 << endl;
    return 0;
}
