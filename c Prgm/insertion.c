#include<stdio.h>
int main()
{
    int a[100],n,k,i,j,temp;

    printf("how many elemants");
    scanf("%d",&n);
    printf("enter the elements of array");
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    for(k=1;k<=n-1;k++)
    {
        temp=a[k];
        j=k-1;
        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];
            j=j-1;

        }
        a[j+1]=temp;

    }

    for(i=0;i<n;i++)
       printf("%d  ",a[i]);

}