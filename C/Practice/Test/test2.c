#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct stack{
    Node *top;
    int have;
}stack;

int m,n;

void push(stack *s,int data){
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=s->top;
    s->top=newnode;
}
int pop(stack *s){
    Node *temp=s->top;
    s->top=s->top->next;
    free(temp);
}

int check(stack *s,int *a){
    int cnt=0;
    int latest;
    if(a[0]<=m){
        for(int i=1;i<a[0];i++){
            push(s,i);
            s->have++;
        }
        latest=a[0];
    }
    else return 0;
    for(cnt=1;cnt<n;cnt++){
        if((a[cnt]>s->top->data)&&((a[cnt]-latest+s->have)<=m)){
            for(int i=latest+1;i<a[cnt];i++){
                push(s,i);
                s->have++;
            }
            latest=a[cnt];
        }
        else if(a[cnt]==s->top->data){
            pop(s);
            s->have--;
        }
        else return 0;
    }
    return 1;
}

int main(){
    int k;
    scanf("%d %d %d",&m,&n,&k);
    int unchecked[k][n];
    for (int i=0;i<k;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&unchecked[i][j]);
        }
    }
    stack s;
    Node *dummyhead;
    s.top=dummyhead=(Node *)malloc(sizeof(Node));
    s.top->data=-1;s.top->next=NULL;s.have=0;
    for(int i=0;i<k;i++){
        if(check(&s,unchecked[i])) printf("YES\n");
        else printf("NO\n");
        s.have=0;s.top=dummyhead;
    }
}