#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int Max=10000;
void bucket_sort(int a[],int len){
    int Bucket[10][len];
    //创建一个桶
    for (int cnt = 1;cnt<Max;cnt*=10){
        //按照最大指数来进行cnt次step
        memset(Bucket,0,sizeof(Bucket));
        //初始化
        for (int i=0;i<len;i++){
            Bucket[(a[i]/cnt)%10][i]=a[i];
            //各位上数字即下标
        }
        int k=0;
        for (int i=0;i<10;i++){
            for (int j=0;j<len;j++){
                if(Bucket[i][j]){
                    a[k++]=Bucket[i][j];
                    //重返原数组
                }
            }
        }
    }
}
void Print(int a[],int len){
    for (int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int a[100];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bucket_sort(a,n);
    Print(a,n);
}