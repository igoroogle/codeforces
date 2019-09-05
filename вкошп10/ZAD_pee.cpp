#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    int a = 10;
    int *ptr = &a;
    *ptr = 7;
    cout << *ptr << endl;
    cout << a << endl;
    return 0;
}
