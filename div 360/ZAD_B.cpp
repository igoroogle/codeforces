#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main()
{
    int n, i;
    scanf("%s", &s);
    printf("%s", s);
    n = strlen(s);
    for (i = n - 1; i >= 0; i--)
        printf("%c", s[i]);
    return 0;
}
