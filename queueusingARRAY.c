#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q,int x ){
    if(q->rear==q->size-1){
        printf("Queue is FULL");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q){
    int x=-1;
    if(q->rear==q->front){
        printf("Queue is EMPTY");
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

void display(struct Queue q){
    int i=0;
    for(i=q.front+1;i<=q.rear;i++){
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}

int main(){
    struct Queue q;
    create(&q,5);
    int x,choice;
    while(1){
        printf("\nEnter choice:\n1)Add to Queue\n2)Display queue\n3)Delete queue elements\n4)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                printf("\nEnter element to add:\n");
                scanf("%d",&x);
                enqueue(&q,x);
                break;
            }
            case 2: {
                printf("\nQueue elements:\n");
                display(q);
                break;
            }
            case 3: {
                printf("\nDeleted element: %d\n",dequeue(&q));
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }
}
