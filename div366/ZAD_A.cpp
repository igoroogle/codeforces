#include<bits/stdc++.h>
#define y first
#define x second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    int n;
    cin >> n;
    bool f = 0;
    while (n--)
    {
        if (f)
            printf("I love ");
        else
            printf("I hate ");
        f = !f;
        if (n == 0)
            printf("it\n");
        else
            printf("that ");
    }


    return 0;
}
