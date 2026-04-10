#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int *a, i, n, key, low, high, mid, flag = 0;
    double st, et, tt;

    // printf("\nEnter no of elements");
    // scanf("%d", &n);
    n = 50;

    a = (int*)malloc(n * sizeof(int));

    // printf("\nenter %d elements in sorted order", n);
    for(i = 0; i < n; i++)
      //  scanf("%d", &a[i]);
      a[i]=i+1;

    // printf("\nenter element to search");
    // scanf("%d", &key);
    key = 29;

    low = 0;
    high = n - 1;

    st = clock();
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
        {
            flag = 1;
            break;
        }
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    et = clock();

    tt = (double)(et - st) / CLOCKS_PER_SEC;
    printf("\ntime spent: %f", tt);

    if(flag == 1)
        printf("\n%d element is found at %d location", key, mid);
    else
        printf("\nelement does not exist");
}


