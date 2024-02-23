#include <stdio.h>
int main(){
    char dict[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int x,n,cnt=0;
    scanf("%d%d",&x,&n);
    char a[40];
    while(x!=0){
        a[cnt++]=dict[x%n];
        x/=n;
    }
    for (int i = cnt-1; i >= 0; i--) {
        printf("%c",a[i]);
    }
}