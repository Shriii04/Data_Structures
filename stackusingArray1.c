#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *s;
};

void create(struct stack *st){
    printf("Enter Size ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}

void push(struct stack *st,int x){
    if(st->top==st->size-1){
        printf("Stack OverFlow\n");
    }
    else{
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct stack *st){
    int x=-1;
    if(st->top==-1){
        printf("Stack Underflow\n");
    }
    else{
        x=st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct stack st,int index){
    int x=-1;
    if(st.top-index+1<0){
        printf("Invalid Index\n");
    }
    x=st.s[st.top-index+1];
    return x;
}

int isEmpty(struct stack st){
    if(st.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack st){
    if(st.top==st.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int stacktop(struct stack st){
    if(st.top==-1){
        return -1;
    }
    else{
        return st.s[st.top];
    }
}

void display(struct stack st){
    int i=0;
    for(i=st.top;i>=0;i--){
        printf("%d",st.s[i]);
        printf("\n");
    }
}

int main(){
    struct stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    push(&st,60);
    display(st);

    // printf("\n%d \n",pop(&st));
    // display(st);

    // printf("\n%d",isEmpty(st));
    // printf("\n%d",isFull(st));

    printf("\nElement at specific position: %d\n",peek(st,2));
    printf("\nElement at top: %d \n",stacktop(st));
}
