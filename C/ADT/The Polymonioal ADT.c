#include<stdio.h>
#include<stdlib.h>


typedef struct Node *PtrToNode;
struct Node {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;
/* Nodes are sorted in decreasing order of exponents.*/  


Polynomial Add( Polynomial a, Polynomial b ){
    struct Node* dummyhead=(struct Node*)malloc(sizeof(struct Node));
    dummyhead->Coefficient=dummyhead->Exponent=0;
    dummyhead->Next=0;
    Polynomial pa=a,pb=b,sum=dummyhead;
    
    while(a&&b){
            if(a->Exponent>b->Exponent){
                sum->Next=a;
                sum=a;
                pa=a=a->Next;
            }
            else if(b->Exponent>a->Exponent){
                sum->Next=b;
                sum=b;
                pb=b=b->Next;
            }
            else{
                if(a->Coefficient+b->Coefficient){
                    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
                    node->Exponent=a->Exponent;
                    node->Coefficient=a->Coefficient+b->Coefficient;
                    sum->Next=node;
                    sum=node;
                }
                a=a->Next;
                b=b->Next;
                free(pa);
                free(pb);
                pa=a;pb=b;
            }
    }
    if(a){
        sum->Next=a;
    }
    else if(b){
        sum->Next=b;
    }
    return dummyhead;
}

