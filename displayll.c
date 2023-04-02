#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
}*first;

void create(int A[],int n){
    int i;
    
    struct node *t,*temp;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    temp=first;

    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        temp->next=t;
        //printf("%p\n",t);
        temp=t;
    }
}

void display(struct node *p){

    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}

void displayrecurssion(struct node *p){
    
    if(p!=NULL){
        printf("%d\t",p->data);
        displayrecurssion(p->next);
    }
}
int main(){
    int A[]={3,10,19,33,12,4};
    create(A,6);
    display(first);
    displayrecurssion(first);


}