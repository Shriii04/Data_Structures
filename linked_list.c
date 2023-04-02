#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));

    return (head);
}
void insert(int n, struct node *head)
{
    int x, i;
    struct node *ptr;
    printf("Enter the data of node 1: ");
    scanf("%d", &x);
    head->data = x;
    head->next = NULL;
    ptr = head;
    for (int i = 2; i <= n; i++)
    {
        ptr->next = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d: ", i);
        scanf("%d", &x);
        ptr = ptr->next;
        ptr->data = x;
        ptr->next = NULL;
    }
}
void print(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}
struct node *insertlist(struct node *head, int key)
{
    int x;
    printf("Enter the value of node: ");
    scanf("%d", &x);
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->data = x;
    q->next = NULL;
    if (key == -1)
    {
        q->next = head;
        head = q;
    }
    else
    {
        struct node *ptr;
        ptr = head;
        while (ptr->data != key && ptr != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr != NULL)
        {
            q->next = ptr->next;
            ptr->next = q;
        }
    }
    return head;
}
struct node *delete(struct node *head, int key)
{
    struct node *p, *q;
    if (head->data == key)
    {
        p = head;
        head = head->next;
        free(p);
    }
    else
    {
        p = head;
        while (p->data != key)
        {
            q = p;
            p = p->next;
        }
        if (p != NULL)
        {
            q->next = p->next;
            free(p);
        }
        else
        {
            printf("key not found!!\n");
        }
    }
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
int main()
{
    int n, key;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node *head;
    head = create();
    insert(n, head);
    print(head);
    printf("\nEnter the number of key:");
    scanf("%d", &key);

    head = insertlist(head, key);
    print(head);

    head = delete (head, key);
    print(head);
    head = reverse(head);
    print(head);
    return 0;
}
