#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int max(int a,int b,int c){
    if(a>=b){
        if(a>=c)
            return a;
    }
    else if(b>=c){
        return b;
    }
    return c;
}
int border(int l,int r,int a[]){
    int lsum=0,lmax=0,rsum=0,rmax=0;
    int mid=(l+r+1)/2;
    for (int i=mid-1;i>=l;i--){
        lsum+=a[i];
        if(lsum>lmax) lmax=lsum;
    }
    for (int i=mid;i<=r;i++){
        rsum+=a[i];
        if(rsum>rmax) rmax=rsum;
    }
    int bd=lmax+rmax;
    return bd;

}


int DC(int l,int r,int a[]){
    int maxl,maxr;
    if(l==r){
        if(a[l]>0) return a[l];
        else return 0;
    }
    int mid=(l+r+1)/2;
    maxl=DC(l,mid-1,a);
    maxr=DC(mid,r,a);
    int across=border(l,r,a);
    return max(maxl,maxr,across);
}
int online(int a[],int n){
    int Max=0,ThisSum=0;
    for (int i=0;i<n;i++){
        ThisSum+=a[i];
        if(ThisSum>Max) Max=ThisSum; 
        if(ThisSum<0) ThisSum=0;
    }
    return Max;

}
int main(){


    int a[8]={0,-2,7,9,-9,-3,9,4};
    
    printf("DCmax=%d\nonlineMax=%d\n",DC(0,7,a),online(a,8));
}