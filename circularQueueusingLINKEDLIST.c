#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node * next;
}* front=NULL,*rear=NULL;
void display(){
if(front==NULL){
printf("Queue is Empty");
}
else{
struct node *temp=front;
while(temp!=rear){
printf("%d ",temp->data);
temp=temp->next;
}
printf("%d ",temp->data);
}
}
void enqueue(int x){
if(rear==NULL){
rear=(struct node *)malloc(sizeof(struct node));
rear->data=x;
rear->next=NULL;
front=rear;
}
else{
struct node * temp=(struct node *)malloc(sizeof(struct node));
temp->data=x;
temp->next=front;
rear->next=temp;
rear=temp;;
}
}
int dequeue(){
int x;
if(front==NULL){
printf("Queue is empty");
}
else{
struct node * temp=front;
x=temp->data;
front=front->next;
free(temp);
}
return x;
}
int menu()
{
printf("\nChoose from below option -\n");
int opt;
printf("1 : Enqueue element \n2 : Dequeue element \n3 : Print the Queue\n");
printf("\nEnter the option- ");
scanf(" %d", &opt);
return opt;
}
int main()
{
char more = 'y';
while (more == 'y')
{
int opt = menu();
if (opt == 1)
{
printf("How many elements ? ");
int n;
scanf(" %d", &n);
for (int i = 0; i < n; i++)
{
int ele1;
printf("Data : ");
scanf(" %d", &ele1);
enqueue(ele1);
}
}
else if (opt == 2)
{
int x=dequeue();
printf("Deleted Element is %d\n", x);
// delete only 1 element.
}
else if (opt == 3)
{
display();
}
printf("\nMore tasks to do ? (y/n) ");
scanf(" %c", &more);
}
}


