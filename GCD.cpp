//GCD (Greatest Common Divisor)
//LCM (Least Common Multiple)
//Nejvetsi spolecny delitel = Eukliduv algoritmus
//Nemensi spolecny násobek = lcm(a,b) = |a*b|/gcm(a,b) 
#include <stdio.h>
#include <math.h>

int gcd(int n, int m){
    int r = 0;
    while (m !=0)
    {
        r = (n%m);
        n = m;
        m = r;
    }
    
    return n;
}
int lcm(int res){
    int temp = 0;

    temp = abs(60*45);
    temp /= res;

    return temp;
}


int main(int argc, char **argv){
    int n1=60,n2 =45;
    
    int res= gcd(n1,n2);
    printf("Nejvetsi spolecny delitel cisel %d, a %d, je %d \n",n1,n2,res); //15

    int res2 = lcm(res);
    printf("Nejvetsi spolecny nasobek cisel %d, a %d, je %d \n",n1,n2,res2); //180
 return 0;   
}