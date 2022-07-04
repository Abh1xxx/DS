#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node *left;
    struct node *right;
};
typedef struct node node;
node *root=NULL;

node *insertion(node *tree,int num);
void inorder(node *tree);
int count=1;
int main()
{
    int choice,digit=1,con;
    do
    {
        printf("\n1\t:Insertion\n");
        printf("\n2\t:Display\n");
        printf("\n3\t:End");
        printf("Enter your choice\t::");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
               printf("Enter integer numbers ::To quit enter 0\n");
             //  scanf("%d",digit);
               while(digit!=0)
               {
                   root=insertion(root,digit);
                   scanf("%d",&digit);
               }
               break;
            case 2:
               printf("\nInorder display");
               inorder(root);
               break;
            case 3:
            printf("\nProgram terminated");
               exit(0);   
        }
        printf("To continue press 1");
        scanf("%d",&con);
    }while(con==1);
    return 0;
}
node *insertion(node *p,int digit)
{
    if(p==NULL)
    {
        p=(node*)malloc(sizeof(node));
        p->left=p->right=NULL;
        p->num=digit;
        count++;
    }
    else
    {
        if (count%2==0)
        {
            p->left=insertion(p->left,digit);
        }
        else
        {
            p->right=insertion(p->right,digit);
        }
    }
    return p;
}

void inorder(node *p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d\t->",p->num);
        inorder(p->right);
    }
}