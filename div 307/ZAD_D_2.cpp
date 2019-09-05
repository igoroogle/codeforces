#include <iostream>
using namespace std;
typedef long long ll;
ll m;
struct fib
    {
        ll x,y,z,t;
        void null()
            {
                x = 1 % m;
                y = 1 % m;
                z = 1 % m;
                t = 0 % m;
            }
        fib operator*(fib ar2)
            {
                fib k;
                k.x = (x*ar2.x % m + y * ar2.z % m) % m;
                k.y = (x*ar2.y % m + y * ar2.t % m) % m;
                k.z = (z*ar2.x % m + t * ar2.z % m) % m;
                k.t = (z*ar2.y % m + t * ar2.t % m) % m;
                return k;
            }
        fib operator%(ll m)
            {
                fib k;
                k.x = x % m;
                k.y = y % m;
                k.z = z % m;
                k.t = t % m;
                return k;
            }
    };
template <class cl> cl powt(cl,ll);
int main ()
    {
        ll n,k,l,i,ans,stp,fb,a,b;
        cin >> n >> k >> l >> m;
        ans = 1 % m;
        fib g;
        g.null();
        fb = powt(g,n+1).x;
        stp = powt(2%m,n);
        a = fb % m;
        b = (stp + m - fb) % m;
        for (i=0;i<l;i++)
            {
                if (k%2) ans = (ans * b) % m;
                else ans = (ans * a) % m;
                k/=2;
            }
        if (k > 0) ans = 0;
        cout << ans << endl;
    }
template <class cl> cl powt(cl h,ll n)
    {
        cl r;
        if (n == 1) return h%m;
        else if (n%2)
            {
                r = powt(h%m,n/2);
                return (((r%m)*(r%m) % m)*(h%m)) % m ;
            }
        else
            {
                r = powt(h%m,n/2);
                return ((r%m)*(r%m)) % m;
            }
    }
