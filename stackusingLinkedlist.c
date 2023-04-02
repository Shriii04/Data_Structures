#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=NULL;

void push(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    if(top==NULL){
        p->next=NULL;
    }
    else{
        p->next=top;
    }
    top=p;
}

int pop(){
    if(top==NULL){
        printf("No element in stack");
    }
    else{
        struct node *p=top;
        int data = top->data;
        top=top->next;
        free(p);
        return data;
    }
}
void display(){
    if(top == NULL){
        printf("No element in stack");
    }
    else{
        struct node *p=top;
        while(p->next!=NULL){
            printf("%d\n",p->data);
            p=p->next;
        }
        printf("%d",p->data);
    }
    
}

int main(){
    int x,n;
    printf("Enter Size : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data ");
        scanf("%d",&x);
        push(x);
    }
    printf("\nElements of stack\n");
    display();
    printf("\nAfter pop\n");
    x=pop();
    printf("Popped Element%d ",x);
    printf("\nStack after pop\n");
    display();
}