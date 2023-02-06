#include<stdio.h>
int main(){
    int n=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    int temp=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}