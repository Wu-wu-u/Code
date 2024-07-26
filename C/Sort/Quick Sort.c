#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionsort(int a[],int n);
void swap(int *a,int *b);
int median3(int a[],int left,int right);
void Qsort(int a[],int left,int right);
void QuickSort(int a[],int n);

int main(){
    int a[]={1,3,5,7,9,2,4,6,8,10};
    QuickSort(a,10);
    for (int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
}


/*---------------------------------------*/
void insertionsort(int a[],int n){
    for (int i=1;i<n;i++){
        int temp= a[i];
        int j;
        for (j=i-1;j>=0&&a[j]>temp;j--){
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


int median3(int a[],int left,int right){
    int mid=(left+right)/2;
    if(a[left]>a[mid]) swap(&a[left],&a[mid]);
    if(a[left]>a[right]) swap(&a[left],&a[right]);
    if(a[mid]>a[right]) swap(&a[mid],&a[right]);
    swap(&a[mid],&a[right-1]);
    return a[right-1];

}
void Qsort(int a[],int left,int right){
    if (left+10<=right){
    int pivot=median3(a,left,right);
    int i=left,j=right-1;
    for ( ; ;){
        while (a[++i]<pivot){}
        while (a[--j]>pivot){}
        if (i<j) swap(&a[i],&a[j]);
        else break;    
    }
    swap(&a[i],&a[right-1]);
    Qsort(a,left,i-1);
    Qsort(a,i+1,right);
    }
    else insertionsort(a+left,right-left+1);
}


void QuickSort(int a[],int n){
    Qsort(a,0,n-1);
}