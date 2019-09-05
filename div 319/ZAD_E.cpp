#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 2500000000;
ll x[1000010], y[1000010], ind[1000010];
ll sum = 0, sum2, sum3;
int main()
{
    srand(time(0));
    int i, j, n;
    cin >> n;
    for (i = 0; i < n; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
            ind[i] = i + 1;
        }
    for (i = 0; i < n - 1; i++)
        sum += abs(x[i] - x[i + 1]) +  abs(y[i] - y[i + 1]);
    while (sum > INF)
    {
        i = ((rand() << 15) ^ rand()) % n;
        j = ((rand() << 15) ^ rand()) % n;
        sum2 = sum;
        if (i > 0)
            sum2 = sum2 - (abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1])) + (abs(x[j] - x[i - 1]) + abs(y[j] - y[i - 1]));
        if (i < n - 1)
            sum2 = sum2 - (abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1])) + (abs(x[j] - x[i + 1]) + abs(y[j] - y[i + 1]));
        if (j > 0)
            sum2 = sum2 - (abs(x[j] - x[j - 1]) + abs(y[j] - y[j - 1])) + (abs(x[i] - x[j - 1]) + abs(y[i] - y[j - 1]));
        if (j < n - 1)
            sum2 = sum2 - (abs(x[j] - x[j + 1]) + abs(y[j] - y[j + 1])) + (abs(x[i] - x[j + 1]) + abs(y[i] - y[j + 1]));
        if (sum2 <= sum)
        {
            sum = sum2;
            swap(x[i], x[j]);
            swap(y[i], y[j]);
            swap(ind[i], ind[j]);
        }
    }
    for (i = 0; i < n; i++)
        printf("%d ", ind[i]);
    return 0;
}
