#include <stdio.h>

int a[101],  c[101];
void change(int x) {
    int y=0;
    for(int i=1;i<=100;i++) {
        a[i]=a[i]*x+y;
        y=a[i]/10;
        a[i]=a[i]%10;
    }
}

void qh(){
    int y=0;
    for (int i=1;i<=100;i++) {
        c[i] += a[i]+y ;
        y = c[i] / 10;
        c[i] = c[i] % 10;
    }
}

int main() {
    int n;
    int lc=100;
    scanf("%d",&n);
    a[1]=1;
    for (int i=1;i<=n;i++){
        change(i);
        qh();
    }
    for (int i=1;i<=100;i++){
        if(c[lc]==0&&lc>0)
            lc--;
    }
    for(int i=lc;i>=1;i--)
        printf("%d",c[i]);
}


