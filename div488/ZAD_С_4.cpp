#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;
const ld EPS = 1E-12;
ll x1[5], y1[5], x2[5], y2[5];
bool val[204][204], val2[204][204];

bool totr(ll x1, ll y1, ll x, ll y, ll x2, ll y2) {
    ll a, b, c;
    a = y-y2;
    b = x2-x;
    c = -(a*x+b*y);
    return (((((x1-x)*(x2-x)+(y1-y)*(y2-y))>=0)
    && (((x1-x2)*(x-x2)+(y1-y2)*(y-y2))>=0)) && ((a*x1+b*y1+c) == 0));
}

bool potr(ll ax1, ll ay1, ll ax2, ll ay2, ll bx1, ll by1, ll bx2, ll by2) {
    ll v1, v2, v3, v4;
    v1 = ((bx1-bx2)*(ay1-by2))-((by1-by2)*(ax1-bx2));
    v2 = ((bx1-bx2)*(ay2-by2))-((by1-by2)*(ax2-bx2));
    v3 = ((ax1-ax2)*(by1-ay2))-((ay1-ay2)*(bx1-ax2));
    v4 = ((ax1-ax2)*(by2-ay2))-((ay1-ay2)*(bx2-ax2));
    return (((v1 * v2)<0) && ((v3 * v4)<0));
}

bool intersec(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
   if ((potr(x1,y1,x2,y2,x3,y3,x4,y4)) || (totr(x1,y1,x3,y3,x4,y4))
    || (totr(x2,y2,x3,y3,x4,y4)) || (totr(x3,y3,x1,y1,x2,y2))
    || (totr(x4,y4,x1,y1,x2,y2))) {
       return true;
    } else {
        return false;
    }
}

ll vec(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 * y2 - x2 * y1);
}

ll prov(ll xs, ll ys) {
    ll ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans += vec(x1[i + 1] - x1[i], y1[i + 1] - y1[i], xs - x1[i], ys - y1[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 4; ++i) {
        cin >> x1[i] >> y1[i];
        val[x1[i] + 101][y1[i] + 101] = true;
    }
    x1[4] = x1[0];
    y1[4] = y1[0];

    for (int i = 0; i < 4; ++i) {
        cin >> x2[i] >> y2[i];
        val2[x2[i] + 101][y2[i] + 101] = true;
    }
    x2[4] = x2[0];
    y2[4] = y2[0];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (intersec(x1[i], y1[i], x1[i + 1], y1[i + 1], x2[i], y2[i], x2[i + 1], y2[i + 1])) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    for (int i = min(min(x1[0], x1[1]), min(x1[2], x1[3])); i <= max(max(x1[0], x1[1]), max(x1[2], x1[3])); ++i) {
        for (int j = min(min(y1[0], y1[1]), min(y1[2], y1[3])); j <= max(max(y1[0], y1[1]), max(y1[2], y1[3])); ++j) {
            //cout << i << ' ' << j << endl;
            if (val2[i + 101][j + 101]) {
                /*cout << j << endl;
                cout << i << ' ' << j << endl;*/
                cout << "YES\n";
                return 0;
            }
        }
    }


    ll toans = prov(x1[0], y1[0]);
    //cout << toans << endl;

    for (int i = 0; i < 4; ++i) {
        cin >> x2[i] >> y2[i];
        if (prov(x2[i], y2[i]) == toans) {
            cout << "YES\n";
            return 0;
        }
    }

    x2[4] = x2[0];
    y2[4] = y2[0];
    for (int i = 0; i < 5; ++i) {
        swap(x1[i], x2[i]);
        swap(y1[i], y2[i]);
    }

    toans = prov(x1[0], y1[0]);
    for (int i = 0; i < 4; ++i) {
        if (prov(x2[i], y2[i]) == toans) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}
