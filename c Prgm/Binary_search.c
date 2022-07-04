#include<stdio.h>
int main()
{
    int a[100],item,n,i,flag=0,temp,j,upper,lower,mid,k;
    printf("Enter the size of array \t:");
    scanf("%d",&n);
    printf("\nEnter the elements into the array\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nEnter the item to be Searched\t:");
    scanf("%d",&item);

    //insertion sort
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

    printf("\n\t\tARRAY\n");
    for(i=0;i<n;i++)
       printf("\t%d \t",a[i]);

    //Binary search
    lower=0;
    upper=n-1;
    while(lower<=upper)
    {
        mid=(lower+upper)/2;
        if(a[mid]==item)
        {
            flag=1;
            printf("\n %d found at the location %d\n",item,mid);
            break;
        }
        else if(item>a[mid])
           lower=mid+1;
        else
           upper=mid-1;
    }
    if(flag==0)
    {
        printf("\n%d do not exist in the array\n",item);
    }
    return 0;
}
