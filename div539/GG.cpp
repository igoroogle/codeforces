#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[50010];

int main() {
    ios_base::sync_with_stdio(0);
    multiset<int> t;
    t.insert(2);
    t.insert(1);
    t.insert(1);
    cout << *t.begin() << endl;
    t.erase(1);
    cout << *t.begin() << endl;
    t.erase(1);
    cout << *t.begin() << endl;
}
