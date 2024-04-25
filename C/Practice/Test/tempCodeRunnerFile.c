#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree_node * tree;
typedef struct tree_node {
    int data;
    tree left;
    tree right;
} ;

typedef struct StackNode {
    tree node;
    struct StackNode* next;
} *Stack;

tree create(int data){
    tree node=(tree)malloc(sizeof(struct tree_node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

void define_trees(int *post,int *inorder,tree T,int n){
    if(n==1) {
        T->left=T->right=NULL;
        return;
    }
    if(n==0) return;
    
    //T->data=post[n-1];
    if(inorder[n-1]!=T->data) T->right=create(inorder[n-1]);
    else T->right=NULL;
    //int l_post[30],l_inorder[30],r_post[30],r_inorder[30];
    int ln=0,rn=0;
    for (int i=0;i<n;i++){
        if(inorder[i]==T->data){
            ln=i;
            break;
        }
        //l_inorder[i]=inorder[i];
        //l_post[i]=post[i];
    }
    rn=n-ln-1;
    if(post[ln-1]!=T->data) T->left=create(post[ln-1]);
    else T->left=NULL;
    // for (int i=ln+1;i<n;i++){
    //     r_post[i]=post[i];
    //     r_inorder[i]=inorder[i];
    // }
    define_trees(post,inorder,T->left,ln);
    define_trees(post+ln,inorder+ln+1,T->right,rn);

}

void push(Stack* top, tree node) {
    Stack new_node = (Stack)malloc(sizeof(struct StackNode));
    new_node->node = node;
    new_node->next = *top;
    *top = new_node;
}

tree pop(Stack* top) {
    if (*top == NULL) {
        return NULL;
    }
    Stack temp = *top;
    *top = (*top)->next;
    tree popped = temp->node;
    free(temp);

    return popped;
}

void zigzagging(tree T){
    if (T == NULL) {
        return;
    }

    Stack s1=NULL,s2=NULL;
    push(&s1,T);
    int level=1;
    while(s1){
        tree node=pop(&s1);
        printf("%d ",node->data);
        if(level%2==0){
            if(node->left) push(&s2,node->left);
            if(node->right) push(&s2,node->right);
        }
        else{
            if(node->right) push(&s2,node->right);
            if(node->left) push(&s2,node->left);
        }
        if(s1==NULL) {
            level++;
            Stack temp=s1;
            s1=s2;
            s2=temp;
        
        }
    }
}

void preorderTraversal(tree node) {
    if (node == NULL)
        return;

    // 访问根节点
    printf("%d ", node->data);

    // 递归地遍历左子树
    preorderTraversal(node->left);

    // 递归地遍历右子树
    preorderTraversal(node->right);
}




int main(){
    int n;
    tree T;
    T=(tree)malloc(sizeof(tree));
    int post[40],inorder[40];
    memset(post,0,sizeof(post)/sizeof(int));memset(inorder,0,sizeof(inorder)/sizeof(int));
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    for (int i=0;i<n;i++){
        scanf("%d",&post[i]);
    }
    T->data=post[n-1];
    define_trees(post,inorder,T,n);
    //preorderTraversal(T);
    //printf("\n");
    zigzagging(T);

}