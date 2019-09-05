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
struct pod
    {
        ll x,y,poz;
        bool operator<(pod g)
            {
                return (x < g.x)  || ((x == g.x) && (y < g.y) ) || ((x == g.x) && (y == g.y) && (poz < g.poz) );
            }
    };
bool comp(pod a,pod b)
    {
        if (a < b) return 1;
        else return 0;
    }
pod gt[100010];
ll sm[100010],val[27];
string s;
int main ()
    {
        int i,n,kl = 0;
        ll ss = 0,l,r,m,l1,l2;
        pod pf;
        for (i=0;i<26;i++) scanf("%I64d",&val[i]);
        cin >> s;
        n = s.length();
        sm[0] = 0;
        for (i=1;i<=n;i++) sm[i] = sm[i-1] + val[ll(s[i-1] - 'a')];
        //for (i=0;i<=n;i++) cout << 'k' << ' ' << sm[i] << endl;
        //cout << sm[n] - sm[n-1] << endl;
        for (i=n;i>=1;i--)
            {
                kl++;
                gt[kl-1].x = sm[n] - sm[i-1];
                gt[kl-1].y = ll(s[i-1] - 'a');
                gt[kl-1].poz = i;
            }
        sort(gt,gt+kl,comp);
        //for (i=0;i<kl;i++) cout << gt[i].x << ' ' << gt[i].y << ' ' << gt[i].poz << endl;
        for (i=1;i<n;i++)
            {
                l = 0;
                r = kl-1;
                pf.x = sm[n]- sm[i];
                pf.y = ll(s[i-1] - 'a');
                pf.poz = i+1;
                while (l < r)
                    {
                        m = (l+r) / 2;
                        if (gt[m] < pf) l = m + 1;
                        else r = m;
                    }
                /*if (i == 2)
                    {
                        cout << pf.x << ' ' << pf.y << ' ' << pf.poz << endl;
                        cout << l << endl;
                        cout << (pf < gt[2]) << "fuuuuuck" << endl;
                    }*/
                if ( (gt[l].poz > i) && (gt[l].y == pf.y) && (gt[l].x == pf.x) ) l1 = l;
                else l1 = -1;
                l = 0;
                r = kl-1;
                pf.x = sm[n] - sm[i];
                pf.y = ll(s[i-1] - 'a')+1;
                pf.poz = i+1;
                while (l < r)
                    {
                        m = (l+r) / 2;
                        if (gt[m] < pf) l = m + 1;
                        else r = m;
                    }
                pf.y--;
                if ( (gt[l].poz > i) && (gt[l].y == pf.y) && (gt[l].x == pf.x) ) l2 = l;
                else if ( (l-1 >=0) && (gt[l-1].poz > i) && (gt[l-1].y == pf.y) && (gt[l-1].x == pf.x) ) l2 = l-1;
                else l2 = -1;
                /*if (i == 2)
                    {
                        cout << l1 << ' ' << l2 << endl;
                    }*/
                if ( (l1 != -1) && (l2 != -1) ) ss+=l2-l1+1;
            }
        cout << ss << endl;
        return 0;
    }
