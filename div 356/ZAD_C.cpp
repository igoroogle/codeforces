#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int pr[103];
string s;
int main()
{
    int n, i, j, d, ans = 0, kl = 0, x;
    for (i = 2; i <= 50; i++)
    {
        pr[kl++] = i;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                kl--;
                break;
            }
        }
    }
    bool f = 1;
    for (i = 0; i < 4; i++)
    {
        cout << pr[i] << endl;
        fflush(stdout);
        cin >> s;
        if (s[0] == 'n')
            continue;
        f = 0;
        x = i;
        cout << pr[i] * pr[i] << endl;
        fflush(stdout);
        cin >> s;
        if (s[0] == 'y')
        {
            cout << "composite" << endl;
            fflush(stdout);
            return 0;
        }

        break;
    }

    if (f)
    {
        cout << "prime" << endl;
        fflush(stdout);
        return 0;
    }


    for (i = x + 1; ((pr[i] * pr[x] <= 100) && (i < kl)); i++)
    {
        cout << pr[i] << endl;
        fflush(stdout);
        cin >> s;
        if (s[0] == 'n')
            continue;
        cout << "composite" << endl;
        fflush(stdout);
        return 0;
    }

    cout << "prime" << endl;
    fflush(stdout);
    return 0;
    return 0;
}
