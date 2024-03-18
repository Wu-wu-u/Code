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
void reverse(List *plist);
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
    reverse(&list);
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
        if(!q&&p->value==del){
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

void reverse(List *plist){
    Node *p1=plist->head,*p2=p1,*p3=NULL;
    if(p1->next){
        p3=p1->next;
    }
    else return;
    while(p3){
        p2=p3;
        p3=p3->next;
        p2->next=p1;
        p1=p2;
    }
    plist->head->next=NULL;
    plist->head=p2;
}