#include <stdio.h>
#include <math.h>
int maxfactor(int x,int y){
    int a,b;
    a=y%x;//余数作除数
    b=x;//除数作被除数
    if(a==0)
        return x;
    else if(a!=1)
        maxfactor(a,b);
    else return 1;
}


int main(){
    int factor,multiple,a,b,count=0;
    scanf("%d %d",&factor,&multiple);
    int max= sqrt(factor*multiple);
    for(a=factor;a<max;a++){
        b=(multiple*factor)/a;
        if(factor== maxfactor(a,b))
            count++;
    }
    printf("%d",2*count);
}
//