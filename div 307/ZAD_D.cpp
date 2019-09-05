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
                k.t = z % m;
                return k;
            }
    };
fib pow1(fib,ll);
ll pow2(ll,ll);
int main ()
    {
        ll n,k,l,i,ans,stp,fb,a,b;
        cin >> n >> k >> l >> m;
        ans = 1 % m;
        fib g;
        g.null();
        fb = pow1(g,n+1).x;
        stp = pow2(2,n);
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
fib pow1(fib h,ll n)
    {
        fib r;
        if (n == 1) return h;
        else if (n%2)
            {
                r = pow1(h,n/2);
                return r*r*h;
            }
        else
            {
                r = pow1(h,n/2);
                return r*r;
            }
    }
ll pow2(ll h,ll n)
    {
        ll r;
        if (n == 0) return 1 % m;
        else if (n == 1) return h % m;
        else if (n%2)
            {
                r = pow2(h,n/2) % m;
                return (r*r%m)*h%m;
            }
        else
            {
                r = pow2(h,n/2)%m;
                return r*r%m;
            }
    }
