#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[103];
int main()
{
    int n, i, cnt = 0, ind;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(;;)
    {
        ind = 0;
        for (i = 1; i < n; i++)
            if (a[i] >= a[ind])
                ind = i;
        if (ind == 0)
            break;
        a[ind]--;
        a[0]++;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}

