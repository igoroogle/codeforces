#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
char s1[100010], rs1[100010], s2[100010], rs2[100010];
ll c[100010];
bool srv(char s1[], char s2[]);
int main()
{
    ll n, i, j, a = 0, b = 0, a1, b1, l1 = 0, l2, ans;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d", &c[i]);
    for (i = 0; i < n; i++)
    {
        scanf("%s", &s2);
        l2 = strlen(s2);
        for (j = 0; j <= l2; j++)
            rs2[j] = s2[j];
        reverse(rs2, rs2 + l2);
        a1 = INF;
        b1 = INF;
        if (srv(s1, s2))
        a1 = min(a1, a);
        if (srv(rs1, s2))
            a1 = min(b, a1);
        if (srv(s1, rs2))
            b1 = min(a + c[i], b1);
        if (srv(rs1, rs2))
            b1 = min(b + c[i], b1);
        l1 = l2;
        for (j = 0; j <= l2; j++)
            s1[j] = s2[j];
        for (j = 0; j <= l2; j++)
            rs1[j] = rs2[j];
        a = a1;
        b = b1;
    }

    ans = min(a, b);
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}

bool srv(char s1[], char s2[])
{
    int l1 = strlen(s1), l2 = strlen(s2), i, ln;;
    ln = min(l1, l2);
    for (i = 0; i < ln; i++)
        if (s1[i] != s2[i])
            return (s1[i] < s2[i]);
    return (l1 <= l2);
}
