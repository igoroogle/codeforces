#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1440;
int main()
{
    int s, s1, s2, t, t1, t2;
    scanf("%d:%d", &s1, &s2);
    scanf("%d:%d", &t1, &t2);
    s = s1 * 60 + s2;
    t = t1 * 60 + t2;
    s = (s + MOD - t) % MOD;
    printf("%d%d:%d%d\n", s / 60 / 10, s / 60 % 10, s % 60 / 10, s % 60 % 10);
    return 0;
}
