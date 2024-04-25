#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 1 to MaxVertexNum */

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

bool IsTopSeq( LGraph Graph, Vertex Seq[] );

int main()
{
    int i, j, N;
    Vertex Seq[MaxVertexNum];
    LGraph G = ReadG();
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        for (j=0; j<G->Nv; j++)
            scanf("%d", &Seq[j]);
        if ( IsTopSeq(G, Seq)==true ) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}

/* Your function will be put here */
LGraph ReadG(){
    int Nv, Ne;
    scanf("%d %d", &Nv, &Ne);
    LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = Nv;
    Graph->Ne = Ne;
    for(int i=0; i<Nv; i++){
        Graph->G[i].FirstEdge = NULL;
    }
    for(int i=0; i<Ne; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        PtrToAdjVNode newNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        newNode->AdjV = v2;
        newNode->Next = Graph->G[v1].FirstEdge;
        Graph->G[v1].FirstEdge = newNode;
    }
    return Graph;
}

bool IsTopSeq( LGraph Graph, Vertex Seq[] ){
    int inv[MaxVertexNum+1];
    for(int i=0;i<=Graph->Nv;i++) inv[i]=0;
    for (int i=0;i<Graph->Nv;i++){
        for (PtrToAdjVNode p=Graph->G[i].FirstEdge;p!=NULL;p=p->Next){
            inv[p->AdjV]++;
        }
    }
    for (int i=0;i<Graph->Nv;i++){
        if(inv[Seq[i]]){
            return false;
        }
        else{
            for (PtrToAdjVNode p=Graph->G[Seq[i]].FirstEdge;p!=NULL;p=p->Next){
            inv[p->AdjV]--;
        }
        }
    }
    return true;
}