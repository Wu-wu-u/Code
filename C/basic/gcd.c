#include<stdio.h>

int gcd(int m,int n){
    if (n>m){
        int temp=n;
        n=m;
        m=temp;
    }
    int rem;
    while(n>0){
        rem=m%n;
        m=n;
        n=rem;
    }
    //结束时即整除 此时有（m,0)
    return m;
}

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("The gcd of %d and %d is %d\n",x,y,gcd(x,y));
}