#include<stdio.h>

int BS(int a[],int x,int n){
    int l=0,r=n-1,mid=(l+r)/2;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]<x){
            l=mid+1;
        }
        else if(a[mid]>x){
            r=mid-1;
        }
        else return mid;
        
    }
    return -1;
}



int main(){
    int x;
    scanf("%d",&x);
    int a[10]={1,5,8,23,54,211,985,1213,12138,77777};
    int result=BS(a,x,10);
    if(result==-1) printf("Not Found\n");
    else printf("index=%d\nx=%d\n",result,x);

}