#include<stdio.h>

int heapify(int a[],int N,int parent){
    int largest,left,right;
    largest = parent;
    left = 2*parent+1;
    right =2*parent+2;

    if(left<N && a[left]>a[largest]){
        largest=left;
    }

    if(right<N && a[right]>a[largest]){
        largest=right;
    }

    if(parent!=largest){
        int temp =a[parent];
        a[parent]=a[largest];
        a[largest]=temp;
        heapify(a,N,largest);
    }
}

void heapsort(int a[],int N){
    for(int i=N/2-1;i>=0;i--){
        heapify(a,N,i);
    }
    for(int i=N-1;i>=0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}

int main(){
    printf("Enter size of array: ");
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    heapsort(a,n);

    printf("Sorted Array\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}