#include<stdio.h>
#include<stdlib.h>

#define Max 2
typedef struct stack{
    int data[Max];
    int top;
}stack;

void init(stack *s){
    s->top=-1;
}

void push(int x, stack *s){
    s->top=s->top+1;  
    s->data[s->top]=x;
}

int full(stack *s){
    if(s->top=Max-1){
        return 1;
    }
    return 0;
}
int empty(stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int pop(stack *s){
    int x=0;
    x=s->data[s->top];
    s->top=s->top-1;
    return (x);
}
void display(stack *s){
    for(int i=s->top;i>=0;i--){
        printf("%d\n",s->data[i]);
    }
}
int main(){
    int x;
    stack s;
    init(&s);
    for(int i=0;i<Max;i++){
        printf("Enter Value ");
        scanf("%d",&x);
        push(x,&s);
    }

    printf("Value in Stack: ");
    printf("\n");
    display(&s);
    printf("\n");
    printf("After Pop ");
    x=pop(&s);
    printf("\n%d",x);
    x=full(&s);
    printf("\n");
    if(x==1){
        printf("Stack full ");
    }
    else{
        printf("Stack not full");
    }
    x=empty(&s);
    printf("\n");
    if(x==1){
        printf("Stack empty ");
    }
    else{
        printf("Stack not empty");
    }
}