#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void func1(int x1, int y1, int x2, int y2, int x3, int y3);
void func2(int x1, int y1, int x2, int y2, int x3, int y3, int f, int s, int t);
void sfunc(int x1, int y1, int x2, int y2, int x3, int y3, int f, int s, int t);
int main()
{
    int x1, y1, x2, y2, x3, y3;
    char f = 'A', s = 'B', t = 'C';
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (x1 > y1)
        swap(x1, y1);
    if (x2 > y2)
        swap(x2, y2);
    if (x3 > y3)
        swap(x3, y3);
    func1(x1, y1, x2, y2, x3 ,y3);
    func1(x1, y1, x2, y2, y3 ,x3);
    func1(x1, y1, y2, x2, x3 ,y3);
    func1(x1, y1, y2, x2, y3 ,x3);
    func1(y1, x1, x2, y2, x3 ,y3);
    func1(y1, x1, x2, y2, y3 ,x3);
    func1(y1, x1, y2, x2, x3 ,y3);
    func1(y1, x1, y2, x2, y3 ,x3);

    sfunc(x1, y1, x2, y2, x3, y3, f, s, t);
    sfunc(x1, y1, x3, y3, x2, y2, f, t, s);
    sfunc(x2, y2, x1, y1, x3, y3, s, f, t);
    sfunc(x2, y2, x3, y3, x1, y1, s, t, f);
    sfunc(x3, y3, x1, y1, x2, y2, t, f, s);
    sfunc(x3, y3, x2, y2, x1, y1, t, s, f);
    cout << -1 << endl;
    return 0;
}

void func1(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int i, j;
    if ((x1 + x2 + x3 == y1) && (y1 == y2) && (y2 == y3))
    {
            cout << y1 << endl;
            for (i = 0; i < x1; i++)
            {
                for (j = 0; j < y1; j++)
                    printf("%c", 'A');
                printf("\n");
            }

            for (i = 0; i < x2; i++)
            {
                for (j = 0; j < y2; j++)
                    printf("%c", 'B');
                printf("\n");
            }

            for (i = 0; i < x3; i++)
            {
                for (j = 0; j < y3; j++)
                    printf("%c", 'C');
                printf("\n");
            }
            exit(0);
    }
}
void func2(int x1, int y1, int x2, int y2, int x3, int y3, int f, int s, int t)
{
    int i, j;
    if ((y1 + y2 == y3) && (x1 + x3 == x2 + x3) && (x1 == x2) && (y3 == x1 + x3))
    {
        cout << y3 << endl;
        for (i = 0; i < x1; i++)
        {
            for (j = 0; j < y1; j++)
                printf("%c", f);
            for (j = 0; j < y2; j++)
                printf("%c", s);
            printf("\n");
        }
        for (i = 0; i < x3; i++)
        {
            for (j = 0; j < y3; j++)
                printf("%c", t);
            printf("\n");
        }
        exit(0);
    }
}
void sfunc(int x1, int y1, int x2, int y2, int x3, int y3, int f, int s, int t)
{
    func2(x1, y1, x2, y2, x3 ,y3, f, s, t);
    func2(x1, y1, x2, y2, y3 ,x3, f, s, t);
    func2(x1, y1, y2, x2, x3 ,y3, f, s, t);
    func2(x1, y1, y2, x2, y3 ,x3, f, s, t);
    func2(y1, x1, x2, y2, x3 ,y3, f, s, t);
    func2(y1, x1, x2, y2, y3 ,x3, f, s, t);
    func2(y1, x1, y2, x2, x3 ,y3, f, s, t);
    func2(y1, x1, y2, x2, y3 ,x3, f, s, t);
}
