#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    cout << "left: 1 2 3 4 right: 5 6 7 8\n";
    fflush(stdout);
    cin >> s;
    if (s == "equal")
    {
        cout << "left: 9 right: 10\n";
        fflush(stdout);
        cin >> s;
        if (s == "equal")
        {
            cout << "left: 9 right: 11\n";
            fflush(stdout);
            cin >> s;
            if (s == "equal")
                cout << "answer: 12\n";
            else
                cout << "answer: 11\n";
            fflush(stdout);
            return 0;
        }
        else
        {
            cout << "left: 9 right: 11\n";
            fflush(stdout);
            cin >> s;
            if (s == "equal")
                cout << "answer: 10\n";
            else
                cout << "answer: 9\n";
            fflush(stdout);
            return 0;
        }
    }

    string s1;
    cout << "left: 1 2 3 right: 4 5 6\n";
    fflush(stdout);
    cin >> s1;

    if (s1 == "equal")
    {
        cout << "left: 1 right: 7\n";
        fflush(stdout);
        cin >> s;
        if (s == "equal")
            cout << "answer: 8\n";
        else
            cout << "answer: 7\n";
        fflush(stdout);
        return 0;
    }

    if (s == s1)
    {
        cout << "left: 1 right: 2\n";
        fflush(stdout);
        cin >> s1;
        if (s1 == "equal")
            cout << "answer: 3\n";
        else if (s == s1)
            cout << "answer: 1\n";
        else
            cout << "answer: 2\n";
        fflush(stdout);
        return 0;
    }

    cout << "left: 4 right: 5\n";
    fflush(stdout);
    cin >> s1;
    if (s1 == "equal")
        cout << "answer: 6\n";
    else if (s == s1)
        cout << "answer: 4\n";
    else
        cout << "answer: 5\n";
    fflush(stdout);
    return 0;
}
