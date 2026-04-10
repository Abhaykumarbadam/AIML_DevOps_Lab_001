#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
        int *a,i,flag=0,key,n;
        double st,et,tt;
        printf("\nenter no of elements");
        scanf("%d",&n);
        a=(int*)malloc(n*sizeof(int));
        printf("enter %d elements",n);
        for(i=0;i<n;i++)
        {
                a[i]=i+1;
        }
        printf("\nenter element to search");
        scanf("%d",&key);
        st=clock();
        for(i=0;i<n;i++)
        {
                if(a[i]==key)
                {
                        flag=1;
                        break;
                }
        }
        et=clock();
        tt=(double)(et-st)/CLOCKS_PER_SEC;
        printf("\ntime spent:%f",tt);
        if(flag==0)
                printf("\nelement does not xist");
        else
                printf("\n%d element is found at %d location",key,i);
}


