#include "bits/stdc++.h"

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "vampire"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 7e18;
const ld EPS = 1e-9;
const ld PI = 3.14159265358979310000;
const ll MD = 535355424;
const ll T = 34539;
const int N = 200101;
const int M = 505;
const ll DL = 20000008;
ll st[11], st2[11], a[1000000], k1[12], k2[12], k3[12], a1[110], a2[110], a3[110];
bool b[DL];
int main()
{
    FREOPEN;
    ll i, j, n, k = 0, t, ii, kp, a8, b8, kl = 0;
    cin >> b8 >> a8;
    if (a8 < 7)
    {
        st[2] = 10;
        for (i = 3; i <= a8; i++)
            st[i] = st[i - 1] * 10;
        st2[1] = 9;
        for (i = 2; i <= a8; i++)
            st2[i] = st2[i - 1] * 10 + 9;

        for (i = st[a8 / 2]; i <= st2[a8 / 2]; i++)
            for (j = i + 1; j <= st2[a8 / 2]; j++)
                if ((i * j >= st[a8]) && (i * j <= st2[a8]) && (!b[i * j]))
                {
                    //b[i * j] = 1;
                    for (t = 0; t < 10; t++)
                    {
                        k1[t] = 0;
                        k2[t] = 0;
                        k3[t] = 0;
                    }

                    ii = i;
                    while (ii > 0)
                    {
                        k1[ii % 10]++;
                        ii /= 10;
                    }

                    ii = j;
                    while (ii > 0)
                    {
                        k2[ii % 10]++;
                        ii /= 10;
                    }

                    ii = i * j;
                    while (ii > 0)
                    {
                        k3[ii % 10]++;
                        ii /= 10;
                    }

                    k++;
                    kp = k;
                    for (t = 0; t < 10; t++)
                        if (k1[t]  + k2[t] != k3[t])
                        {
                            k--;
                            break;
                        }

                    if (kp == k)
                    {
                        if (kl < b8)
                        {
                            b[i * j] = 1;
                            a1[kl++] = i;
                            a2[kl - 1] = j;
                            a3[kl - 1] = i * j;
                        }
                    }
                }

        for (i = 0; i < b8; i++)
            printf("%I64d=%I64dx%I64d\n", a3[i], a1[i], a2[i]);
        return 0;
    }

    for (i = 1000; i <= 9999; i++)
            {
                if (kl == b8)
                    break;
                for (j = i + 1; j <= 9999; j++)
                if ((i * j >= 10000000) && (i * j < DL) && (!b[i * j]))
                {

                    if (kl == b8)
                        break;
                    for (t = 0; t < 10; t++)
                    {
                        k1[t] = 0;
                        k2[t] = 0;
                        k3[t] = 0;
                    }

                    ii = i;
                    while (ii > 0)
                    {
                        k1[ii % 10]++;
                        ii /= 10;
                    }

                    ii = j;
                    while (ii > 0)
                    {
                        k2[ii % 10]++;
                        ii /= 10;
                    }

                    ii = i * j;
                    while (ii > 0)
                    {
                        k3[ii % 10]++;
                        ii /= 10;
                    }

                    k++;
                    kp = k;
                    for (t = 0; t < 10; t++)
                        if (k1[t]  + k2[t] != k3[t])
                        {
                            k--;
                            break;
                        }

                    if (kp == k)
                    {
                        if (kl < b8)
                        {
                            b[i * j] = 1;
                            a1[kl++] = i;
                            a2[kl - 1] = j;
                            a3[kl - 1] = i * j;
                        }
                    }
                }
            }
    //cout << "fghjk";
    for (i = 0; i < b8; i++)
    {
        printf("%I64d", a3[i]);
        kl = 0;
        j = a3[i];
        while (j > 0)
        {
            kl++;
            j /= 10;
        }

        for (j = kl + 1; j <= a8; j++)
            printf("0");
        printf("=");
        printf("%I64d", a1[i]);
        kl = 0;
        j = a1[i];
        while (j > 0)
        {
            kl++;
            j /= 10;
        }
        for (j = kl + 1; j <= a8 / 2; j++)
            printf("0");
        printf("x");
        printf("%I64d", a2[i]);
        kl = 0;
        j = a2[i];
        while (j > 0)
        {
            kl++;
            j /= 10;
        }
        for (j = kl + 1; j <= a8 / 2; j++)
            printf("0");
        printf("\n");
    }
    /*for (i = 0; i < b8; i++)
            printf("%I64d=%I64dx%I64d\n", a3[i], a1[i], a2[i]);*/
}


/*





*/


