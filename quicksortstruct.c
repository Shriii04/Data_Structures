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
    swap++;
}

int partition(struct employee a[], int low, int high)
{
    int pivot = low;
    int i = low;
    int j = high;
    while (i < j)
    {
        while (a[i].id <= a[pivot].id)
        {
            i++;
        }
        while (a[j].id > a[pivot].id)
        {
            j--;
        }

        if (i < j)
        {   
            swap(a,i,j);
            // int temp = a[i].id;
            // a[i].id = a[j].id;
            // a[j].id = temp;
        }
    }

    swap(a,pivot,j);
    // int temp = a[pivot].id;
    // a[pivot].id = a[j].id;
    // a[j].id = temp;

    return j;
}

void quicksort(struct employee a[], int low, int high)
{
    int i = low;
    int j = high;
    if (i < j)
    {
        int index = partition(a, low, high);
        quicksort(a, low, index - 1);
        quicksort(a, index + 1, high);
    }
}

int main(){
    int n=5;
    struct employee s[5];
    for(int i=0;i<5;i++){
        printf("Enter name, id, and salary of employee %d: ", i+1);
        scanf("%s %d %d", s[i].name, &s[i].id, &s[i].salary);
    }

    quicksort(s,0,n-1);

    printf("\nSorted by id:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t%d\t%d\n", s[i].name, s[i].id, s[i].salary);
    }
    return 0;

}  