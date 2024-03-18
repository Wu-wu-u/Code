#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>


typedef struct Data{
    int value;
    int l;
    int r;
}Data;
Data Max; 
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

Data LR(int l,int r,int A[]){
    int mid = (l+r+1)/2;
    int lmax=A[mid-1],rmax=A[mid];
    int lsum=0,rsum=0;
    int L=mid-1,R=mid;
    for(int i=mid-1;i>=l;i--){
        lsum+=A[i];
        if(lsum>lmax){
            L=i;
            lmax=lsum;
        }
    }
    for(int i=mid;i<=r;i++){
        rsum+=A[i];
        if(rsum>rmax){
            R=i;
            rmax=rsum;
        }
    }
    Data ThroughMax;
    ThroughMax.value=lmax+rmax;
    ThroughMax.l=L;
    ThroughMax.r=R;
    return ThroughMax;
}


int DC(int l,int r,int A[]){
    if(l==r) {
        if(A[l]>Max.value){
            Max.value=A[l];
            Max.l=l;
            Max.r=r;
        }
        return A[l];
    }
    int mid=(l+r+1)/2;
    Data through=LR(l,r,A);
    int s1=DC(l,mid-1,A),s2=DC(mid,r,A),s3=through.value;
    int result=max(s1,s2,s3);
    if(result>Max.value){
        if(result==s1){
            Max.value=s1;
            Max.l=l;
            Max.r=mid-1;
        }
        else if(result==s2){
            Max.value=s2;
            Max.l=mid;
            Max.r=r;
        }
        else if(result==s3){
            Max.value=s3;
            Max.l=through.l;
            Max.r=through.r;
        }
    }
    return result;
}

int main(){


    int a[8]={0,-2,7,9,-9,-13,29};
    DC(0,6,a);
    printf("i=%d j=%d max=%d\n",Max.l,Max.r,Max.value);
}