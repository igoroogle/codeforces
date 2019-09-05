#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1;
    srand(time(0));
    cin >> s;
    cout << "left: 1 2 3 right: 4 5 6\n";
    fflush(stdout);
    cin >> s;
    if (s != "equal")
    {
        cout << "left: 1 2 3 right: 7 8 9\n";
        fflush(stdout);
        cin >> s1;
        if (s1 == "equal")
        {
            cout << "left: 4 right: 5\n";
            fflush(stdout);
            cin >> s1;
            if (s1 == "equal")
                cout << "answer: 6\n";
            else if (s1 == s)
                cout << "answer: 5\n";
            else
                cout << "answer: 4\n";
            fflush(stdout);
            return 0;
        }
        s = s1;
        cout << "left: 1 right: 2\n";
        fflush(stdout);
        cin >> s1;
        if (s1 == "equal")
            cout << "answer: 3\n";
        else if (s1 == s)
            cout << "answer: 1\n";
        else
            cout << "answer: 2\n";
        fflush(stdout);
        return 0;
    }

    cout << "left: 7 8 right: 9 10\n";
    fflush(stdout);
    cin >> s;
    if (s == "equal")
    {
        cout << "left: 10 right: 11\n";
        fflush(stdout);
        cin >> s1;
        if (s1 == "equal")
            cout << "answer: 12\n";
        else
            cout << "answer: 11\n";
        fflush(stdout);
        return 0;
    }

    cout << "left: 7 right: 8\n";
    fflush(stdout);

    cin >> s1;
    if (s1 != "equal")
    {
        if (s == s1)
            cout << "answer: 7\n";
        else
            cout << "answer: 8\n";//uuuddffddfdfddddsssss1sssdsdsjkdhjk
        fflush(stdout);
        return 0;
    }

    if (rand() % 2)
            cout << "answer: 9\n";
        else
            cout << "answer: 10\n";
    fflush(stdout);
    return 0;
}
