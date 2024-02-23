#include<stdio.h>
#include <string.h>
char s[100];
int a[100],b,c[100],la,x;
void trans(char s[],int a[],int la)
{
    for(int i=0;i<la;i++){
        a[la-i]=s[i]-'0';
    }
}

int remove_zero(int a[],int la){
    for(int i=1;i<=la;i++){
        if(a[la]==0&&la>0)
            la--;
    }
    return la;
}

void print(int c[],int la){
    for (int i=la;i>=1;i--){
        printf("%d",c[i]);
    }
}

int main(){
    scanf("%s %d",&s,&b);
    la= strlen(s);
    trans(s,a,la);
    for (int i=0;i<la;i++){
        c[la-i]=(x*10+a[la-i])/b;
        x=(x*10+a[la-i])%b;
    }
    la=remove_zero(c,la);
    print(c,la);
}
