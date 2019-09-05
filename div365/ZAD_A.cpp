#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    int n, m, c, s1  = 0, s2 = 0;
    cin >> n;
    while (n--)
    {
        scanf("%d%d", &m, &c);
        if (m > c)
            s1++;
        else if (m < c)
            s2++;
    }

    if (s1 > s2)
        cout << "Mishka\n";
    else if (s1 < s2)
        cout << "Chris\n";
    else
        cout << "Friendship is magic!^^\n";
    return 0;
}
