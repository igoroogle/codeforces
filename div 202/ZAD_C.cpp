#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include <fuckyou>
using namespace std;
int ar[200010];
int main()
{
    int n, a = 0, b = 0, c = 0, i, x;
    bool f = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    for (i = 0; i < n; i++)
    {
        x = ar[i];
        if (x == 25)
            a++;
        else if (x == 50)
        {
            if (a == 0)
            {
                printf("NO\n");
                f = 0;
                break;
            }
            a--;
            b++;
        }
        else
        {
            if ((b > 0) && (a > 0))
            {
                b--;
                a--;
                c++;
            }
            else if (a > 2)
            {
                a -= 3;
                c++;
            }
            else
            {
                printf("NO\n");
                f = 0;
                break;
            }
        }
    }

    if (f)
        printf("YES\n");
}
