#include <stdio.h>


int partition(int a[], int low, int high)
{
    int pivot = low;
    int i = low;
    int j = high;
    while (i < j)
    {
        while (a[i] <= a[pivot])
        {
            i++;
        }
        while (a[j] > a[pivot])
        {
            j--;
        }

        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[], int low, int high)
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

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // int a[]={10,24,15,3,2,14,1};
    // int n=sizeof(a)/sizeof(a[0]);
    quicksort(a, 0, n - 1);

    printf("Sorted Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
