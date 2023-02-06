#include <stdio.h>

void mergesort(int a[], int low, int high)
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

void merge(int a[], int low, int k, int high)
{
    int result[20], i, j, l = 0;
    i = low;
    j = k + 1;

    while (i <= k && j <= high)
    {
        if (a[i] < a[j])
        {
            result[l] = a[i];
            i++;
            l++;
        }
        else
        {
            result[l] = a[j];
            j++;
            l++;
        }
    }

    while (i <= k)
    {
        result[l] = a[i];
        i++;
        l++;
    }
    while (j <= high)
    {
        result[l] = a[j];
        j++;
        l++;
    }

    for (int m = 0; m < l; m++)
    {
        a[low + m] = result[m];
    }
}


int main()
{
    int n;
    printf("Size of array: ");
    scanf("%d",&n);
    int a[n];
    //int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
