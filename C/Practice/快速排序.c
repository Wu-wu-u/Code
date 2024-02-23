#include <stdio.h>
int a[100];
void sort(int *s,int n){
    int *l;int *r; //起末的指针
    l=s;r=s+n-1;
    if(n<2) return; //递归结束的条件
    int temp=*s; //永远把第一个元素作为split point
    while(l<r){
        while(*r>temp) r--;
        *l=*r;              //末指针左移，直至条件不符合，扔到左空处
        while (*l<temp) l++;
        *r=*l;              //起指针右移，直至条件不符合，扔到右空处
    }
    *r=temp; //重合处 即为split point
    sort(s,l-s); //左区间 进行操作
    sort(r+1,n-(r-s)-1); //右区间 进行操作
}

int main(){
    int n;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}