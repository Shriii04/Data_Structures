#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   

void insert()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void delete ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nElements in Queue\n");  
        while(ptr != NULL)   
        {  
            printf("%d\t",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}

void main ()  
{  
    int choice;   
    while(1){
        printf("\nEnter choice:\n1)Add to Queue\n2)Display queue\n3)Delete queue elements\n4)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                insert();
                break;
            }
            case 2: {
                display();
                break;
            }
            case 3: {
                delete();
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