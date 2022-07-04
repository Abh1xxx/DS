#include<stdio.h>
void linear_search(int a[],int x,int y);
void binary_search(int a[],int p,int j);
void insertion_sort(int arr[],int y);
void printarray(int a[],int z);

int main()
{
    int a[100],n,i,choice,con,item;
    printf("Enter number of elements \t");
    scanf("%d",&n);
    printf("Enter %d elements in the array\n",n);
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    do{
        printf("\nEnter the item to be searched\t:");
        scanf("%d",&item);
        printf("\n\t1.Linear search\n\t2.Binary search");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
               linear_search(a,n,item);
               break;
            case 2:
               binary_search(a,n,item);
               break;
        }
        printf("To continue press 1");
        scanf("%d",&con);
    }while(con==1);
    return 0;
}

void printarray(int arr[],int n)
{
    int i,flag=0;
    for(i=0;i<n;i++)
       printf("  %d  ",arr[i]);
}

void linear_search(int arr[],int n,int x)
{
  int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            flag=1;
            break;
        }
    }  
    printarray(arr,n);      
    if(flag==1)
       printf("\n%d found at the location %d\n",x,++i);           
    else
      printf("\nDo not exist in the give array\n"); 
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void binary_search(int a[],int n,int x)
{
    int lower,upper,mid,flag=0;
    insertion_sort(a,n);
    printarray(a,n);
    lower=0;
    upper=n-1;
    while(lower<=upper)
    {
        mid=(lower+upper)/2;
        if(a[mid]==x)
        {
            flag=1;
            printf("\n %d found at the location %d\n",x,mid+1);
            break;
        }
        else if(x>a[mid])
           lower=mid+1;
        else
           upper=mid-1;
    }
    if(flag==0)
    {
        printf("\n%d do not exist in the array",x);
    }
}