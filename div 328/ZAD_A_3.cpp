#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1E18;
char a[11][11];
int main()
{
    ll i, j, k, b = INF, w = INF;
    bool f;

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            cin >> a[i][j];

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
        {
            f = 1;

            if (a[i][j] == 'W')
            {
                for (k = i - 1; k >= 0; k--)
                    if (a[k][j] != '.')
                    {
                        f = 0;
                        break;
                    }

                if (f)
                    w = min(w, i);
            }

            if (a[i][j] == 'B')
            {
                for (k = i + 1; k < 8; k++)
                    if (a[k][j] != '.')
                    {
                        f = 0;
                        break;
                    }

                if (f)
                    b = min(b, 7 - i);
            }

        }

    if (w <= b)
        cout << "A\n";
    else
        cout << "B\n";
    return 0;
}
