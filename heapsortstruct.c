#include<stdio.h>

struct employee{
    char name[20];
    int salary;
    int id;
};


void swap(struct employee s[], int i, int j) {
    struct employee temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}


int heapify(struct employee a[],int N,int parent){
    int largest,left,right;
    largest = parent;
    left = 2*parent+1;
    right =2*parent+2;

    if(left<N && a[left].id>a[largest].id){
        largest=left;
    }

    if(right<N && a[right].id>a[largest].id){
        largest=right;
    }

    if(parent!=largest){
        swap(a,parent,largest);
        // int temp =a[parent];
        // a[parent]=a[largest];
        // a[largest]=temp;
        heapify(a,N,largest);
    }
}

void heapsort(struct employee a[],int N){
    for(int i=N/2-1;i>=0;i--){
        heapify(a,N,i);
    }
    for(int i=N-1;i>=0;i--){
        swap(a,0,i);
        // int temp=a[0];
        // a[0]=a[i];
        // a[i]=temp;
        heapify(a,i,0);
    }
}

int main(){
    struct employee s[5];
    int n=5;
    for(int i=0;i<5;i++){
        printf("Enter name, id, and salary of employee %d: ", i+1);
        scanf("%s %d %d", s[i].name, &s[i].id, &s[i].salary);
    }

    heapsort(s,n);

    printf("\nSorted by id:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t%d\t%d\n", s[i].name, s[i].id, s[i].salary);
    }
    return 0;
}