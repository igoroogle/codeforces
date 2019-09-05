#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)

using namespace std;
typedef long long ll;
typedef long double ld;
ll h[26], hs[252];
char a[252][252];
bool use[252];
int ch[252], nch[252], let[26][252];
int d1[252], d2[252];

bool cmp(int i, int j) {
    if ((use[i]) && (use[j]) && (hs[i] == hs[j])) {
        return true;
    } else {
        return false;
    }
}

ll palin(int n) {
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        if (!use[i]) {
            continue;
        }
        int k = (i>r ? 0 : min (d1[l+r-i], r-i));
        while (i+k < n && i-k >= 0 && cmp(i + k, i - k))  ++k;
        d1[i] = k--;
        if (i+k > r)
        l = i-k,  r = i+k;
    }


    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        if (!use[i]) {
            continue;
        }
        int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
        while (i+k-1 < n && i-k >= 0 && cmp(i + k - 1, i - k))  ++k;
        d2[i] = --k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (use[i]) {
            ans += d1[i] + d2[i];
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    srand(time(0));
    ll ans = 0;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 26; ++i) {
        h[i] = rand();
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 26; ++k) {
                let[k][j] = 0;
            }
            ch[j] = 0;
            nch[j] = 0;
            hs[j] = 0;
            use[j] = false;
        }

        for (int j = i; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                int vl = a[k][j] - 'a';
                if (let[vl][k] > 0) {
                    if (let[vl][k] % 2) {
                        --nch[k];
                    } else {
                        --ch[k];
                    }
                }

                ++let[vl][k];
                hs[k] += h[vl];
                if (let[vl][k] % 2) {
                    ++nch[k];
                } else {
                    ++ch[k];
                }

                if (nch[k] <= 1) {
                    use[k] = true;
                } else {
                    use[k] = false;
                }
            }

            ans += palin(n);
        }
    }

    cout << ans << '\n';
}


/*
cfefc
5 1
c
f
e
f
c



5 47
cdccgcgfdeffegeggdfffffeegcdedfdgedddfcdfgeceed
cfefdfdffcfgdccggggfdddefeffcdedgcdcgddccdgddec
fgdgdefffffgffeeecffeecegdgdfgfdegddffeffedeedg
edfegffggccfeggfededcgdfecccdggeeecgcfddgfdcggc
efggcccdgdefceecgdegdddfdfdfgfccecgdfcefggggccg


10 47
cdccgcgfdeffegeggdfffffeegcdedfdgedddfcdfgeceed
cfefdfdffcfgdccggggfdddefeffcdedgcdcgddccdgddec
fgdgdefffffgffeeecffeecegdgdfgfdegddffeffedeedg
edfegffggccfeggfededcgdfecccdggeeecgcfddgfdcggc
efggcccdgdefceecgdegdddfdfdfgfccecgdfcefggggccg
cfffdgdcdccgdcfgfgccegcccgcdcgcgdgfedfddfdfgffc
dgegceddddfdeeefdcfgcgefgcccgedcfdffgegccegdefd
gedeeegegecdcgdcecfdcdedgcfcddecccgdfcdgecdgggd
fgcdfdcegcedfefcgeffefgdcggcegfggdccdgfededfeee
geddcgdcefdfgdfegcdfdcfgeeededgfeeggddggdfgddfe
*/
