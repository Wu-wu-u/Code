#include <stdio.h>
#include <string.h>
#include <math.h>
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};
int a[100][100];
int main(){

    int i=1,j=1,cnt=2,t=0;
    int n;
    a[i][j]=1;
    scanf("%d",&n);
    while(cnt<=n*n){
        if(i+di[t]>n||i+di[t]<1||j+dj[t]>n||j+dj[t]<1)
            t=(t+1)%4;
        if(a[i+di[t]][j+dj[t]]!=0)
            t=(t+1)%4;
        i+=di[t];
        j+=dj[t];
        a[i][j]=cnt++;
    }
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
