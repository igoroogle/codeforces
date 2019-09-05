#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    int n, k, c;
    cin >> n >> k;
    while (n--)
    {
        scanf("%d", &c);
        if (c % k == 0)
        {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}
