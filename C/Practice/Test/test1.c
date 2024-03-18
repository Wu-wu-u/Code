#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t start, stop;
double total_time;
double duration;
//declaration of start, stop, total_time, duration to record processor time
int iterative_sequential(int a[],int n,int target){
    for (int i=0;i<n;i++){
        if (a[i]==target){
            return i;
        }
    }
    //use 'for loop' to traverse the array
    return 0;
}

int recursive_sequential(int a[],int n,int target,int step){
    //use step from 0 to n-1 to traverse the array and find the target
    if(step>=n){
        return 0;
    }
    //if step is greater than or equal to n,stop searching
    if(a[step]==target){
        return step;
    }
    //if the target is found, return the index
    else{
        return recursive_sequential(a,n,target,step+1);
    }
    //if the target is not found, continue to search by increasing step by 1
}

int iterative_binary(int a[],int n,int target){
    int low=0,high=n-1,mid;
    //initialize low and high
    while(low<=high){
        //use 'while loop' to find the target
        mid=(low+high)/2;
        if(a[mid]<target){
            low=mid+1;
        }
        //if the target is greater than mid, search the right part of the array
        else if(a[mid]>target){
            high=mid-1;
        }
        //if the target is smaller than mid, search the left part of the array
        //plus 1 or minus 1 to low or high to avoid infinite loop
        if(a[mid]==target) return mid;
        //if the target is found, return the index
    }
    return 0;
}

int recursive_binary(int a[],int low,int high,int target){
    int mid=(low+high)/2;
    if(low>high) return 0;
    //if low is greater than high, stop searching
    if (a[mid]==target) return mid;
    //if the target is found, return the index
    if(a[mid]<target) return recursive_binary(a,mid+1,high,target);
    //if the target is greater than mid, search the right part of the array
    else if(a[mid]>target) return recursive_binary(a,low,mid-1,target);
    //if the target is smaller than mid, search the left part of the array
}

void init_arr(int a[],int n){
    for (int i=0;i<n;i++){
        a[i]=i;
    }
}
//initialize the array

int main(){
    int n,*a;
    scanf("%d",&n);
    //input the length of the array
    a=(int *)malloc(n*(sizeof(int)));
    //allocate memory for the array
    init_arr(a,n);

    start = clock();
    for (int i=0;i<100000;i++)
    //set iterations(K) to 100000
    iterative_binary(a,n,n);
    stop = clock();
    total_time = ((double)(stop - start)) / CLOCKS_PER_SEC;
    duration = total_time/100000;
    printf("iterative_binary\n");
    printf("ticks:%d\n", stop - start);
    printf("total_time:%f\n", total_time);
    //calculate the time of iterative_binary

    start = clock();
    for (int i=0;i<100000;i++)
    //set iterations(K) to 100000
    recursive_binary(a,0,n,n);
    stop = clock();
    total_time = ((double)(stop - start)) / CLOCKS_PER_SEC;
    duration = total_time/100000;
    printf("recusive_binary\n");
    printf("ticks:%d\n", stop - start);
    printf("total_time:%f\n", total_time);
    //calculate the time of recursive_binary

    start = clock();
    for (int i=0;i<10000;i++)
    //set iterations(K) to 10000
    iterative_sequential(a,n,n);
    stop = clock();
    total_time = ((double)(stop - start)) / CLOCKS_PER_SEC;
    duration = total_time/10000;
    printf("iterative_sequential\n");
    printf("ticks:%d\n", stop - start);
    printf("total_time:%f\n", total_time);
    //calculate the time of iterative_sequential

    start = clock();
    for (int i=0;i<10000;i++)    
    //set iterations(K) to 10000
    recursive_sequential(a,n,n,0);
    stop = clock();
    total_time = ((double)(stop - start)) / CLOCKS_PER_SEC;
    duration = total_time/10000;
    printf("recursive_sequential\n");
    printf("ticks:%d\n", stop - start);
    printf("total_time:%f\n", total_time);
    //calculate the time of recursive_sequential

    return 0;
}
