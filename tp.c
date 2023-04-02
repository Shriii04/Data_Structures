#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node * create(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp; 
}

struct node * insert(struct node *root,int data){
    if(root==NULL){
    root=create(data);
    }
    else if(data<root->data){
    root->left=insert(root->left,data);
    }
    else{
    root->right=insert(root->right,data);
    }
    return root;
}

struct stack{
    struct node *data;
    struct stack *next;
}*top=NULL;

int isempty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}

void push(struct node *p){
    struct stack *temp;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=p;
    if(top==NULL){
        temp->next=NULL;
    }
    else{
        temp->next=top;
    }
    top=temp;
}

struct node * pop(){
    if(top==NULL){
        printf("No element in stack");
    }
    else{
        struct stack *p=top;
        struct node *data = top->data;
        top=top->next;
        free(p);
        return data;
    }
    return NULL;
}

struct node * Top(){
    if(top==NULL){
        printf("No element in stack");
    }
    else{
        struct node *data = top->data;
        return data;
    }
    return NULL;
}

void inorder(struct node *root){
    while(root!=NULL){
        push(root);
        root=root->left;
    }
    while(!isempty()){
        root=pop();
        printf("%d ",root->data);
        root=root->right;
        while(root!=NULL){
            push(root);
            root=root->left;
        }
    }

}

void inorder_r(struct node * root){
    if(root!=NULL){
        inorder_r(root->left);
        printf("%d ",root->data);
        inorder_r(root->right);
    }
}

void preorder(struct node * root){
    while(root!=NULL){
        printf("%d ",root->data);
        push(root);
        root=root->left;
    }
    while(!isempty()){
        root=pop();
        root=root->right;
        while(root!=NULL){
            printf("%d ",root->data);
            push(root);
            root=root->left;
        }
    }
}

void preorder_r(struct node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder_r(root->left);
        preorder_r(root->right);
    }
}

void postorder(struct node * root){
    struct node * previous =NULL;
    do{
        while(root!=NULL){
            push(root);
            root=root->left;
        }
        while(root==NULL && !isempty()){
            root=Top();
            if(root->right==NULL || root->right==previous){
                printf("%d ",root->data);
                pop();
                previous=root;
                root=NULL;
            }
            else{
                root=root->right;
            }

        }
    }while(!isempty());
}

void postorder_r(struct node * root){
    if(root!=NULL){
        postorder_r(root->left);
        postorder_r(root->right);
        printf("%d ",root->data);
    }
}

/* 
                50
        30              70
    20       40    60        80


*/
int main()
{
struct node *root = NULL;
root = insert(root, 50);
insert(root, 30);
insert(root, 70);
insert(root, 20);
insert(root, 40);
insert(root, 60);
insert(root, 80);
printf("Inorder traversal without recursion:\n");
inorder(root);
printf("\n");
printf("Inorder traversal using recursion:\n");
inorder_r(root);
printf("\n");
printf("Preorder traversal without recursion:\n");
preorder(root);
printf("\n");
printf("Preorder traversal using recursion:\n");
preorder_r(root);
printf("\n");
printf("Postorder traversal without recursion:\n");
postorder(root);
printf("\n");
printf("Postorder traversal using recursion:\n");
postorder_r(root);
printf("\n");


return 0;
}
