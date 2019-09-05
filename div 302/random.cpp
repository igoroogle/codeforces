#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
int main()
    {
        int i;
        printf("500 500 1000000007\n");
        srand(time(NULL));
        for (i=0;i<499;i++) printf("%d ",rand() % 500);
        printf("%d",rand() % 500);
        return 0;
    }
