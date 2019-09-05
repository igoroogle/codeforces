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

            if (a[i][j] == 'W')
                w = min(w, 7 - i);

            if (a[i][j] == 'B')
                b = min(b, i);

        }

    if (w <= b)
        cout << "A\n";
    else
        cout << "B\n";
    return 0;
}
