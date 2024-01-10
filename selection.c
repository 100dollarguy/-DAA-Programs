//
//  selection.c
//  DAA programs
//
//  Created by ROHAN on 10/01/24.
//

#include<stdio.h>
int main()
{
    int i,position,swap,a[100],d,n;
    printf("Enter the No Elements\n");
    scanf("%d",&n);
    printf("Enter %d Integers\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<(n-1);i++)
    {
        position=i;
        for(d=i+1;d<n;d++)
        {
            if(a[position]>a[d])
                position=d;
        }
        if(position!=i)
        {
            swap=a[i];
            a[i]=a[position];
            a[position]=swap;
        }
    }
    printf("Sorted List in Ascending Order is:\n");
    for(i=0;i< n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}
