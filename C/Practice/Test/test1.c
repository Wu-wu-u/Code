#include<stdio.h>
#include<stdlib.h>

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct{
    int Capacity;
    int Size;
    int *Elements;
};





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

void insert(int x,PriorityQueue H){
    if(H->Size==H->Capacity){
        printf("Priority queue is full\n");
        return;
    }
    int p=++H->Size;
    H->Elements[p]=x;
    Percolateup(p,H);
}

int DeleteMin( PriorityQueue H ) 
{ 
    int MinElement; 
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement; 
}

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

int* alloc(int n){
    int *a=(int*)malloc(sizeof(int)*n);
    return a;
}
int min(int a,int b){
    return a<b?a:b;
}

void ReplaceSelectionSortRecursive(int *arr, int n, int memSize, int runCount) {
    if(n<memSize){ 
        for(int i=0;i<n-1;i++){
            printf("%d ",arr[i]);
        }
        printf("%d\n",arr[n-1]);
        return;
    }
    PriorityQueue H = BuildHeap(arr, memSize);
    int *output = alloc(n);
    int *waiting = alloc(n);
    int i = 0, j = 0;

    //printf("Run %d: ", runCount);

    while (i < n) {
        if (H->Size > 0 && (i == 0 || output[i-1] <= H->Elements[1])) {
            output[i] = DeleteMin(H);
            if(i==0) printf("%d", output[i]);
            else
            printf(" %d", output[i]);
            if (i + memSize < n) {
                if (arr[i + memSize] >= output[i]) {
                    insert(arr[i + memSize], H);
                } else {
                    waiting[j++] = arr[i + memSize];
                }
            }
        } else {
            printf("\n");
            while (H->Size > 0) {
                DeleteMin(H);
            }
            for(i=i+memSize;i<n;i++){
                waiting[j++] = arr[i];
                min(j,memSize);
            }
            if (j > 0) {
                ReplaceSelectionSortRecursive(waiting, j, memSize, ++runCount);
                j = 0;
            }
        }

        i++;
    }

    free(output);
    free(waiting);
    free(H->Elements);
    free(H);
}

void ReplaceSelectionSort(int *arr, int n, int memSize) {
    ReplaceSelectionSortRecursive(arr, n, memSize, 1);
}

int main() {
    int n, memSize;
    scanf("%d", &n);
    scanf("%d", &memSize);

    int *arr = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    ReplaceSelectionSort(arr, n, memSize);

    free(arr);

    return 0;
}