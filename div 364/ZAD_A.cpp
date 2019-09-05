#include<bits/stdc++.h>
#define x firsr
#define y second
#define mp make pair
#define pb push_back
using namespace std;
typedef long long ll;
int a[100010];
bool use[100010];
int main()
{
    int n, i, j, sm = 0, kl;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sm += a[i];
    }

    sm /= (n >> 1);

    //cout << sm << endl;
    for (i = 0; i < (n >> 1); i++)
    {
        for (j = 0; j < n; j++)
            if (!use[j])
            {
                use[j] = 1;
                printf("%d ", j + 1);
                kl = a[j];
                break;
            }

        for (j = 0; j < n; j++)
            if ((!use[j]) && (kl + a[j] == sm))
            {
                use[j] = 1;
                printf("%d\n", j + 1);
                break;
            }


    }
    return 0;
}
