#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front,rear;
    int *Q;
};

void create(struct queue *q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct queue *q,int x){
    if((q->rear+1)%q->size==q->front){
        printf("\nQUEUE is FULL");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct queue *q){
    int x=-1;
    if(q->rear==q->front){
        printf("\nQUEUE is EMPTY!!");
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void display(struct queue q){
    int i=q.front+1;
    do{
        printf("%d\n",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}

int main(){
    struct queue q;
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
                printf("\nInvalid choice.\n");
            }
        }
    }
}
