#include <iostream>
#include <string>
using namespace std;
string s;
int main()
    {
        cin >> s;
        int i,j,k,ss = 0,n = s.length();
        for (i=-1;i<n;i++)
            for (j=i;j<n;j++)
                for (k=j;k<n;k++)
                    {
                        if ((i == -1) && (j== -1) && (k == -1)) continue;
                        ss = 0;
                        if (i != -1) ss+=int(s[i]-'0');
                        if (j != i) ss = ss*10 + int(s[j] - '0');
                        if (k != j) ss = ss*10 + int(s[k] - '0');
                        if (ss % 8 == 0)
                            {
                                cout << "YES\n" << ss << endl;
                                return 0;
                            }
                    }
        cout << "NO" << endl;
        return 0;
    }
