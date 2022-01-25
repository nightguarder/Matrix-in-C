#include <stdio.h>
#include <stdlib.h>

int gcd(int n, int m){
    int r = 0;
    while (m !=0)
    {
        r = (n%m);
        n = m;
        m = r;
    }
    printf("Answer is: %d\n",n);
    return n;
}

int lcm(int x,int y){
    int tmp = 0;
    tmp = (x /gcd(x,y)*y);
    printf("Answer is: %d\n",tmp);
    return tmp;
}