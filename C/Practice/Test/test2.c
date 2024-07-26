#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int k,capacity,m;
int hit[200000];
int number[200000];

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;
typedef struct cache{
    struct node *head;
    struct node *tail;
    int size;
}cache;

cache* create_cache(){
    cache *c=(cache*)malloc(sizeof(cache));
    c->size=0;
    c->head=NULL;
    c->tail=NULL;
    return c;
}

void new_enqueue_Cache(cache *c,int data){
    if(c->size==0){
        node *new_node=(node*)malloc(sizeof(node));
        new_node->data=data;
        new_node->next=NULL;
        new_node->prev=NULL;
        c->head=new_node;
        c->tail=new_node;
        c->size++;
        hit[data]++;
        return;
    }
    if(c->size==capacity){
        node *temp=c->tail;
        c->tail=c->tail->prev;
        c->tail->next=NULL;
        hit[temp->data]=0;
        free(temp);
        node *new_node=(node*)malloc(sizeof(node));
        new_node->data=data;
        new_node->next=c->head;
        new_node->prev=NULL;
        c->head->prev=new_node;
        c->head=new_node;
    }
    else
    {
        node *new_node=(node*)malloc(sizeof(node));
        new_node->data=data;
        new_node->next=c->head;
        new_node->prev=NULL;
        c->head->prev=new_node;
        c->head=new_node;
        c->size++;
    }
}

void enqueue_HA(cache *c,cache * Cache,int data){
    if(c->size==0){
        node *new_node=(node*)malloc(sizeof(node));
        new_node->data=data;
        new_node->next=NULL;
        new_node->prev=NULL;
        c->head=new_node;
        c->tail=new_node;
        c->size++;
        hit[data]++;
        return;
    }
    if(hit[data]==0){
        if(c->size==capacity){
            node *temp=c->tail;
            c->tail=c->tail->prev;
            c->tail->next=NULL;
            hit[temp->data]=0;
            free(temp);
            c->size--;
        }
        node *new_node=(node*)malloc(sizeof(node));
        new_node->data=data;
        new_node->next=c->head;
        new_node->prev=NULL;
        c->head->prev=new_node;
        c->head=new_node;
        c->size++;
        hit[data]++;
    }
    else{
        hit[data]++;
        node *temp=c->head;
        while(temp->data!=data){
            temp=temp->next;
        }
        if(temp==c->head){
            ;
        }
        else if(temp==c->tail){
            c->tail=c->tail->prev;
            c->tail->next=NULL;
            temp->prev=NULL;
            temp->next=c->head;
            c->head->prev=temp;
            c->head=temp;
        }
        else{
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            temp->prev=NULL;
            temp->next=c->head;
            c->head->prev=temp;
            c->head=temp;
        }
        if(hit[data]==k){
            c->head=c->head->next;
            c->head->prev=NULL;
            c->size--;
            new_enqueue_Cache(Cache,data);
        }
    }
}



void old_enqueue_Cache(cache *c,int data){
    node *temp=c->head;
    while(temp->data!=data){
        temp=temp->next;
    }
    if(temp==c->head){
        ;
    }
    else if(temp==c->tail){
        c->tail=c->tail->prev;
        c->tail->next=NULL;
        temp->prev=NULL;
        temp->next=c->head;
        c->head->prev=temp;
        c->head=temp;
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->prev=NULL;
        temp->next=c->head;
        c->head->prev=temp;
        c->head=temp;
    }
    
}

void traverse_cache(cache *c){
    node *temp=c->tail;
    if(temp==NULL){
        printf("-");
        return;
    }
    printf("%d",temp->data);
    temp=temp->prev;
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->prev;
    }

    
    printf("\n");
}


int main(){
    scanf("%d %d %d",&k,&capacity,&m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&number[i]);
    }
    cache *Cache=create_cache();
    cache *HA=create_cache();
    for (int i = 0; i < m; i++)
    {
        if(hit[number[i]]<k)
        {
            enqueue_HA(HA,Cache,number[i]);
        }
        else
        {
            old_enqueue_Cache(Cache,number[i]);
        }
    }
    traverse_cache(HA);
    traverse_cache(Cache);

}