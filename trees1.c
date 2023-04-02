#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* lchild;
	struct Node* rchild;
};

struct Queue{
	int size;
	int front;
	int rear;
	struct Node**Q;
};
struct Stack{
	int size;
	int top;
	struct Node **S;
};
void Create(struct Queue*q,int size){
	q->size=size;
	q->front=q->rear=0;
	q->Q=(struct Node*)malloc(q->size*sizeof(struct Node));
	
}
void CreateStack(struct Stack *s,int size){
	s->size=size;
	s->top=-1;
	s->S=(struct Node*)malloc(s->size*sizeof(struct Node));
}
void enqueue(struct Queue*q,struct Node*x){
	if((q->rear+1)%q->size==q->front){
		printf("Queue is full");
	}
	else{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
	}
}
struct Node* dequeue(struct Queue *q){
	struct Node*x=NULL;
	if(q->front==q->rear){
		printf("Queue is Empty");
	}
	else{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}
int isEmpty(struct Queue q){
	return q.front==q.rear;
}
void push(struct Stack *st, struct Node*t){
	if(st->top==st->size-1){
		printf("Stack Full");
	}
	else{
		st->top++;
    st->S[st->top]=t;
	}
}
struct node* pop(struct Stack *st){
	struct Node*x=NULL;
	if(st->top==-1){
		printf("Stack Empty");
	}
	else{
		x=st->S[st->top];
		st->top--;
	}
	return x;
}
int isEmptyStack(struct Stack st){
	if(st.top==-1){
		return 1;
	}
	else{
		return 0;
	}
}


struct Node* treeCreate(){
	struct Node* p,*t;
	struct Queue q;
	Create(&q,100);
	int x;
	printf("Enter Root Value ");
	scanf("%d",&x);
	struct Node*root=(struct Node *)malloc(sizeof(struct Node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	while(! isEmpty(q)){
		p=dequeue(&q);
		printf("Enter left child of %d ",p->data);
		scanf("%d",&x);
		if(x!=-1){
			printf("IN");
			t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		printf("Enter right child of %d ",p->data);
		scanf("%d",&x);
		if(x!=-1){
			t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
	}
	return root;
	
}
void preorder(struct Node*root){
	struct Node *t=root;
	struct Stack st;
	CreateStack(&st,100);
	while(t!=NULL || !isEmptyStack(st)){
		if(t!=NULL){
			printf("%d ",t->data);
			push(&st,t);
			t=t->lchild;
		}
		else{
			t=pop(&st);
			t=t->rchild;
			
		}
	}
}
void postorder(struct Node*root){
	struct Node*t=root;
	struct Stack st;
	CreateStack(&st,100);
	long int temp;
	while(t!=NULL || !isEmptyStack(st)){
		if(t!=NULL){
			push(&st,t);
			t=t->lchild;
		}
		else{
			temp=pop(&st);
			if(temp>0){
				push(&st,-temp);
				t=((struct Node*)temp)->rchild;
			}
			else{
				printf("%d ",((struct Node *)(-1*temp))->data);
				t=NULL;
			}
		}
	}
}
void Inorder(struct Node *root){
	struct Stack st;
	struct Node*t=root;
	int x;
	CreateStack(&st,100);
	while(t!=NULL || !isEmptyStack(st)){
		if(t!=NULL){
			push(&st,t);
			t=t->lchild;
		}
		else{
			t=pop(&st);
			printf(" %d ",t->data);
			t=t->rchild;
		}
	}
	
}
int main(){
	struct Node*root=treeCreate();
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	Inorder(root);
	
}