#include <stdio.h>

struct employee{
    char name[20];
    int id;
    int salary;
};

void swap(struct employee s[], int i, int j) {
    struct employee temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void merge(struct employee a[], int low, int k, int high)
{
    int result[20], i, j, l = 0;
    i = low;
    j = k + 1;

    while (i <= k && j <= high)
    {
        if (a[i].id < a[j].id)
        {
            result[l] = a[i].id;
            //swap(a,i,l);
            i++;
            l++;
        }
        else
        {
            result[l] = a[j].id;
            //swap(a,j,l);
            j++;
            l++;
        }
    }

    while (i <= k)
    {
        result[l] = a[i].id;
        //swap(a,i,l);
        i++;
        l++;
    }
    while (j <= high)
    {
        result[l] = a[j].id;
        //swap(a,j,l);
        j++;
        l++;
    }

    for (int m = 0; m < l; m++)
    {
        a[low + m].id = result[m];
    }
}

void mergesort(struct employee a[], int low, int high)
{
    int k;
    if (low < high)
    {
        k = (low + high) / 2;
        mergesort(a, low, k);
        mergesort(a, k + 1, high);
        merge(a, low, k, high);
    }
}




int main(){
    struct employee s[5];
    int n=5;

    for(int i=0;i<5;i++){
        printf("Enter name, id, and salary of employee %d: ", i+1);
        scanf("%s %d %d", s[i].name, &s[i].id, &s[i].salary);
    }

    mergesort(s,0,n-1);

    printf("\nSorted by id:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t%d\t%d\n", s[i].name, s[i].id, s[i].salary);
    }
    return 0;

}