#include <stdio.h>
#include <math.h>
int a,n,m,x,u;
double all_a[25],all_u[25],up_a[25],up_u[25];
void number_all(){
    all_a[1]=1;
    all_a[2]=1;
    all_u[1]=0;
    all_u[2]=0;
    for (int i=3;i<=n-1;i++){
        all_a[i]=all_a[i-1]+up_a[i-2];
        all_u[i]=all_u[i-1]+up_u[i-2];
    }

}
void number_u(){
    up_a[1]=1;
    up_a[2]=0;
    up_u[1]=0;
    up_u[2]=1;
    for (int i=3;i<=n-1;i++){
        up_a[i]=up_a[i-1]+up_a[i-2];
        up_u[i]=up_u[i-1]+up_u[i-2];
    }
}

void calculate(){
    int result=a*all_a[x]+u*all_u[x];
    printf("%d",result);
}

int main() {
    scanf("%d %d %d %d",&a,&n,&m,&x);
    number_u();
    number_all();
    u=(m-all_a[n-1]*a)/all_u[n-1];
    calculate();
}
//用不同数组来表示不同量的系数！！