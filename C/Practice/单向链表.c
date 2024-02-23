#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node {
    int value;
    struct node *next;
}Node;

typedef struct _list{
    Node *head;
    Node *tail;
}List;
void add(List *,int );
void traversal(List *);
void delete(List *,int);
void clear(List *plist);
int main(){
    List list;
    list.head=list.tail=NULL;
    int number;
    do{
        scanf("%d",&number);
        if(number!=-1){
            add(&list,number);
        }
    } while (number!=-1);
    delete(&list ,4);
    traversal(&list);
    clear(&list);
    return 0;
}

void add(List *plist,int number ){
    Node *p=(Node *) malloc(sizeof (Node));
    p->value=number;
    p->next=NULL;
    if(plist->tail){
        plist->tail->next=p;
        plist->tail=p;
    }
    else plist->head=plist->tail=p;
}

void traversal(List *plist){
    for (Node *p=plist->head;p;p=p->next){
        printf("%d\n",p->value);
    }
}

void delete(List *plist,int del){
    Node *p;
    Node *q=NULL;
    for (p=plist->head;p;q=p,p=p->next){
        if(!q){
            plist->head=p->next;
            free(p);
            break;
        }
        if(p->value==del){
            q->next=p->next;
            free(p);
            break;
        }
    }
}
void clear(List *plist){
    Node *p;
    Node *q;
    for (p=plist->head;p;p=q){
        q=p->next;
        free(p);
    }
}