#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

const ll P = 3237;
const int LEN = 300300;
string st, st1;
ll h[LEN], h1[LEN], step;
int n;

int main()
{
    freopen("ragnarok.in", "r", stdin);
    freopen("ragnarok.out", "w", stdout);

    cin >> st;
    st1 = st;
    n = st.size();

    reverse(st1.begin(), st1.end());

    for (int i = n - 1; i >= 0; i--)
        h[i] = h[i + 1] * P + (st[i] - 'a' + 1);

    step = 1;
    for (int i = 0; i < n; i++)
    {
        h1[i] = (st1[i] - 'a' + 1) * step;
        if (i > 0)
            h1[i] += h1[i - 1];

        step *= P;
    }

    for (int i = 0; i < n; i++)
    {
        if (h[i] == h1[n - i - 1])
        {
            cout << st;
            for (int j = i - 1; j >= 0; j--)
                cout << st[j];

            break;
        }
    }

    return 0;
}
