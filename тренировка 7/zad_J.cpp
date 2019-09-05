#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define x first
#define y second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
int a[22];
void anseq();
int main()
{
    //freopen("smith.in", "r", stdin);
    //freopen("smith.out", "w", stdout);
    srand(time(0));
    int i, x = rand() % 3;//ii
    for (i = 0; i < 12; i++)
        a[i] = i + 1;

    if (x == 1)
    {
        swap(a[0], a[8]);
        swap(a[1], a[9]);
        swap(a[2], a[10]);
        swap(a[3], a[11]);
    }
    else if (x == 2)
    {
        swap(a[4], a[8]);
        swap(a[5], a[9]);
        swap(a[6], a[10]);
        swap(a[7], a[11]);
    }

    if (rand() % 2)
    {
        swap(a[0], a[4]);
        swap(a[1], a[5]);
        swap(a[2], a[6]);
        swap(a[3], a[7]);
    }
    for (i = 0; i < 12; i++)
        swap(a[i], a[rand() % (12 - i)]);
    string s;
    cin >> s;
    cout << "left: " << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << " " << "right: " << a[4] << ' ' << a[5] << ' ' << a[6] << ' ' << a[7] << endl;
    fflush(stdout);
    cin >> s;
    if (s == "equal")
        {
            swap(a[0], a[8]);
            swap(a[1], a[9]);
            swap(a[2], a[10]);
            swap(a[3], a[11]);
            anseq();
        }

    string s1;
    cout << "left: " << a[0] << ' ' << a[1] << " " << "right: " << a[2] << ' ' << a[3] << endl;
    fflush(stdout);
    cin >> s1;
    if (s1 == "less")
    {
        if (s == "more")
        {
            swap(a[0], a[3]);
            swap(a[1], a[4]);
        }

        cout << "left: " << a[0] << " " << "right: " << a[1] << endl;
        fflush(stdout);
        cin >> s1;
        if (s != s1)
            swap(a[0], a[1]);
        cout << "answer: " << a[0] << endl;
        fflush(stdout);
        return 0;
    }

    if (s1 == "more")
    {
        if (s == "less")
        {
            swap(a[0], a[3]);
            swap(a[1], a[4]);
        }
        cout << "left: " << a[0] << " " << "right: " << a[1] << endl;
        fflush(stdout);
        cin >> s1;
        if (s != s1)
            swap(a[0], a[1]);
        cout << "answer: " << a[0] << endl;
        fflush(stdout);
        return 0;
    }
    swap(a[0], a[4]);
    swap(a[1], a[5]);
    swap(a[2], a[6]);
    swap(a[3], a[7]);
    cout << "left: " << a[0] << ' ' << a[1] << " " << "right: " << a[2] << ' ' << a[3] << endl;
    fflush(stdout);
    cin >> s1;
    if (s1 == s)
    {
        swap(a[0], a[2]);
        swap(a[1], a[3]);
    }
    if (rand() % 2)
        swap(a[0], a[1]);
    cout << "answer: " << a[0] << endl;//1221dsssdwssdSsddddddsdsddsssssdddd
    fflush(stdout);
    return 0;
}
void anseq()
{
    string s;
    cout << "left: " << a[0] << " " << "right: " << a[1] << endl;
    fflush(stdout);
    cin >> s;
    if (s == "equal")
    {
        cout << "left: " << a[0] << " " << "right: " << a[2] << endl;
        fflush(stdout);
        cin >> s;
        cout << "answer: ";
        fflush(stdout);
        if (s != "equal")
            cout << a[2] << endl;
        else
            cout << a[3] << endl;
        fflush(stdout);
        exit(0);
    }
    cout << "left: " << a[0] << " " << "right: " << a[2] << endl;
    fflush(stdout);
    cin >> s;
    cout << "answer: ";
    fflush(stdout);
    if (s != "equal")
        cout << a[0] << endl;
    else
        cout << a[1] << endl;
    fflush(stdout);
    exit(0);
}
