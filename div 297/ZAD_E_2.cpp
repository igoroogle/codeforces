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
#include <map>
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
using namespace std;
map <ll,ll> vl[26];
ll t[25];
ll fact[20];
ll kl1 = 0,kl2 = 0,n,k,s,ss = 0;
void rec(ll,ll,ll,ll);
void rec2(ll,ll,ll,ll);
int main ()
    {
        ll i,n1,n2;
        fact[0] = 1;
        fact[1] = 1;
        for (i=2;i<20;i++) fact[i] = ll(i) * fact[i-1];
        cin >> n >> k >> s;
        for (i=0;i<n;i++) cin >> t[i];
        n1 = (n-1) / 2 + 1;
        n2 = n - n1;
        rec(n1,0,0,0);
        rec2(n,n1,0,0);
        cout << ss << endl;
        return 0;
    }
void rec(ll m,ll v,ll sm,ll fc)
    {
        if (sm > s) return;
        if (v >= m)
            {
                vl[fc][sm]++;
                return;
            }
        else
            {
                rec(m,v+1,sm,fc);
                rec(m,v+1,sm+t[v],fc);
                if ( (fc < k) && (t[v] < 20) ) rec(m,v+1,sm+fact[t[v]],fc+1);
            }
    }
void rec2(ll m,ll v,ll sm,ll fc)
    {
        if (sm > s) return;
        if (v == m)
            {
                int i;
                for (i=0;i<=k-fc;i++) ss+=vl[i][s-sm];
                return;
            }
        else
            {
                rec2(m,v+1,sm,fc);
                rec2(m,v+1,sm+t[v],fc);
                if ( (fc < k) && (t[v] < 20) ) rec2(m,v+1,sm+fact[t[v]],fc+1);
            }
    }
