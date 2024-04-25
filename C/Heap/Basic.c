#include<stdio.h>
#include<stdlib.h>

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct{
    int Capacity;
    int Size;
    int *Elements;
};

void insert(int x,PriorityQueue H){
    if(H->Size==H->Capacity){
        printf("Priority queue is full\n");
        return;
    }
    int p=++H->Size;
    H->Elements[p]=x;
    Percolateup(p,H);
}

void Percolateup(int p,PriorityQueue H){
    int x=H->Elements[p];
    for(;H->Elements[p/2]>x;p/=2){
        H->Elements[p]=H->Elements[p/2];
    }
    H->Elements[p]=x;
}


void PercolateDown( int p, PriorityQueue H ){
    int parent=p;
    int child=2*parent;
    int temp=H->Elements[parent];
    while(child<=H->Size){
        if((child!=H->Size)&&(H->Elements[child]>H->Elements[child+1])) child++;
        if(temp<=H->Elements[child]) break;
        else{
            H->Elements[parent]=H->Elements[child];
            parent=child;
            child=2*parent;
        }
    }
    H->Elements[parent]=temp;
}

int DeleteMin( PriorityQueue H ) 
{ 
    int MinElement; 
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement; 
}