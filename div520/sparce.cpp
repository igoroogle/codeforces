#include <bits/stdc++.h>
using namespace std;

template<typename T> class sparceTable {
 public:
    sparceTable() {
        clear();
    }

    sparceTable(T first, T last, function<T(T, T)> g) {
        clear();
        rebuild(first, last, g);
    }

    template<typename It> sparceTable(It first, It last, function<T(T, T)> g) {
        clear();
        rebuild(first, last, g);
    }


    void rebuild(T first, T last, function<T(T, T)> g) {
        f = g;
        sp.resize(1);
        for (auto i = first; i != last; ++i) {
            sp[0].push_back(i);
        }
        build();
    }

    template<typename It> void rebuild(It first, It last, function<T(T, T)> g) {
        f = g;
        sp.resize(1);
        for (auto i = first; i != last; ++i) {
            sp[0].push_back(*i);
        }
        build();
    }

    T get(int l, int r) {
        int lgLen = lgV[r - l + 1];
        return f(sp[lgLen][l], sp[lgLen][r - (1 << lgLen) + 1]);
    }

    void clear() {
        sp.clear();
        lgV.clear();
    }



private:
    function<T(T, T)> f;
    vector<vector<T>> sp;
    vector<int> lgV;
    int n, lgSz;
    void build() {
        n = sp[0].size();
        lgSz = 0;
        lgV.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            if ((1 << (lgSz + 1)) == i) {
                ++lgSz;
            }
            lgV[i] = lgSz;
        }

        sp.resize(lgSz + 1);
        for (int i = 1; i <= lgSz; ++i) {
            sp[i].resize(n);
            for (int j = 0; j < n; ++j) {
                if (j + (1 << (i - 1)) < n) {
                    sp[i][j] = f(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
                } else {
                    sp[i][j] = sp[i - 1][j];
                }
            }
        }
    }
};

int main() {
    sparceTable<int> a(4, 22323, [](int i, int j) {
                            return min(i, j);
                       });
    cout << a.get(5, 17) << endl;

}
