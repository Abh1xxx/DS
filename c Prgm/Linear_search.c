#include<stdio.h>
int main()
{
    int a[100],item,n,i,flag=0;
    printf("Enter the size of array \t:");
    scanf("%d",&n);
    printf("\nEnter the elements into the array\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nEnter the item to be Searched\t:");
    scanf("%d",&item);
    printf("\n\t\tARRAY\n");
    for(i=0;i<n;i++)
       printf("\t%d \t",a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            flag=1;
            break;
        }
    }        
    if(flag==1)
       printf("\n%d found at the location %d\n",item,++i);           
    else
      printf("\nDo not exist in the give array\n"); 
    return 0;
}

