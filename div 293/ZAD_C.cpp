#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cctype>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
using namespace std;
ll pl[100010],nm[100010];
int main ()
    {
        ll i,n,m,k,t = 0,x,v;
        cin >> n >> m >> k;
        for (i=0;i<n;i++)
            {
                scanf("%d",&pl[i]);
                pl[i]--;
                nm[pl[i]] = i;
            }
        for (i=0;i<m;i++)
            {
                scanf("%d",&x);
                v = nm[x-1];
                if (v > 0)
                    {
                        swap(pl[v],pl[v-1]);
                        nm[pl[v]] = v;
                        nm[pl[v-1]] = v-1;
                    }
                t+=v/k+1;
            }
        cout << t << endl;
        return 0;
    }
