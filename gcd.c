#include<stdio.h>
#include<stdlib.h>

int gcd_euclid (int a, int b){
    if(b<=0){
        return a;
    }
    int temp =b;
    b = a%b;
    a=temp;
    return gcd_euclid(a,b);
}

int gcd_conse(int a , int b){
    int i = a<b?a:b;
    while(i>0){
        if(a%i==0 && b%i==0){
            return i;
        }
        i--;
    }
    return 1;
}

int gcd_middle(int a, int b){
    int i=2;
    int prod=1;
    while(a > 1 && b > 1){
        if(a%i==0 && b%i==0){
            a/=i;
            b/=i;
            prod*=i;
        } else if(a%i==0){
            a/=i;
        } else if(b%i==0){
            b/=i;
        } else {
            i++;
        }
    }
    return prod;
}

int main(){
    printf("%d",gcd_euclid(24,4));
    printf("\n%d",gcd_conse(24,4));
    printf("\n%d",gcd_middle(24,4));
    return 0;
}