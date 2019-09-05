#include <iostream>
#include <cstdio>
#include <set>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 2E9;
set< pair<int, int> > t;
char an[10000110];
int an2[10000110];
char s[1000010];
int main()
{
    int n, x, i, kl = 0;
    scanf("%d", &n);
    t.insert(mp(INF, INF));

    while (n--)
    {
        scanf("%s", &s);
        if (s[0] == 'i')
        {
            scanf("%d", &x);
            kl++;
            an[kl - 1] = 'i';
            an2[kl - 1] = x;
            t.insert(mp(x, kl - 1));
            continue;
        }


        if (s[0] == 'r')
        {

            if (t.begin()->x == INF)
            {
                kl++;
                an[kl - 1] = 'i';
                an2[kl - 1] = 0;
                t.insert(mp(-1000000000, kl - 1));
            }

            kl++;
            an[kl - 1] = 'r';
            t.erase(t.begin());
            continue;
        }

        scanf("%d", &x);

        while (t.begin()->x < x)
        {
            kl++;
            an[kl - 1] = 'r';
            t.erase(t.begin());
        }

        if (t.begin()->x != x)
        {
            kl++;
            t.insert(mp(x, kl - 1));
            an[kl - 1] = 'i';
            an2[kl - 1] = x;
        }

        kl++;
        an[kl - 1] = 'g';
        an2[kl - 1] = x;
    }

    printf("%d\n", kl);
    for (i = 0; i < kl; i++)
    {
        if (an[i] == 'r')
        {
            printf("removeMin\n");
            continue;
        }

        if (an[i] == 'g')
        {
            printf("getMin %d\n", an2[i]);
            continue;
        }

        if (an[i] == 'i')
        {
            printf("insert %d\n", an2[i]);
            continue;
        }
    }

    return 0;
}
