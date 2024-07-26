#include<stdio.h>
#include<stdlib.h>

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct{
    int Capacity;
    int Size;
    int *Elements;
};

PriorityQueue BuildHeap(int *a,int n){
    PriorityQueue H=(PriorityQueue)malloc(sizeof(struct HeapStruct));
    H->Capacity=n;
    H->Size=n;
    H->Elements=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++){
        H->Elements[i+1]=a[i];
    }
    for(int i=n/2;i>0;i--){
        PercolateDown(i,H);
    }
    return H;
}

