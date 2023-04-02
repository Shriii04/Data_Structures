#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head,*head1;

struct node *create(struct node *head){
    
    head=(struct node*)malloc(sizeof(struct node));
    return(head);
}
struct node  *insert(struct node *head){
    struct node *p;
    int x;
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter element ");
    scanf("%d",&x);
    head->data=x;
    head->next=NULL;
    p=head;
    for(int i=2;i<=3;i++){
        
        p->next=(struct node*)malloc(sizeof(struct node));
        printf("Enter element ");
        scanf("%d",&x);
        p=p->next;
        p->data=x;
        p->next=NULL;
    }
    return (head);
}

struct node  *delete(struct node *head,int key){
    struct node *p,*q;
    p=head;
    q=head;
    while(p->data!=key){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    if(q==head){
        head=head->next;
    }
    p->next=NULL;
    free(p);
    
    return(head);
}

struct node *deletespecificpos(struct node *head,int pos){
    struct node *p,*q;
    if(pos==1){
        p=head;
        head=head->next;
        free(p);
    }
    else{
        p=head;
        q=NULL;
        for(int i=0;i<pos-1&&p;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            free(p);
        }
    }
    return head;
}
struct node *join(struct node *head,struct node *head1){
    struct node *p,*q;
    p=head;
    q=head1;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
    return head;
}

struct node *reverse(struct node *head)
{
    struct node *p, *q, *r;
    p = NULL;
    q = NULL;
    r = head;

    while (r != NULL)
    {
        p = q;
        q = r;
        r = r->next;
        q->next = p;
    }
    head = q;
    return head;
}

void display(struct node *head){
    struct node *p;
    p=head;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

int main(){
    struct node *head3;
    printf("Enter elements in list 1\n");
    head = create(head);
    head=insert(head);
    printf("Enter elements in list 2\n");
    head1=create(head1);
    head1=insert(head1);
    printf("\nElements in list 1\n");
    display(head);
    printf("Elements in list 2\n");
    display(head1);
    printf("\nAfter joining\n");
    head=join(head,head1);
    display(head);
    printf("\nReverse List\n");
    head=reverse(head);
    display(head);
    printf("\nAfter Deleting\n");
    head=delete(head,10);
    display(head);
    printf("\nAfter Deleting from specific position\n");
    head=deletespecificpos(head,2);
    display(head);
}