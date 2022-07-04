#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) 
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

struct node *insert(struct node *node, int key)
{
   if (node == NULL) 
      return newNode(key);
   if (key < node->key)
      node->left = insert(node->left, key);
   else
      node->right = insert(node->right, key);
    return node;
}




void inorder(struct node *root)
{ 
    if (root != NULL) 
    {
       inorder(root->left);
       printf("%d -> ", root->key);
       inorder(root->right);
    }
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {

    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

void search (struct node *p,int d) 
{
  if (p==NULL)
  {
    printf("\nThe number don't exist");
  }
  else if (d==p->key)
  {
    printf("Number =%d found \n",d);
  }
  else if(d<p->key)
  {
    search(p->left,d);
  }
  else
     search(p->right,d);
}
int main() {
  struct node *root = NULL;
  int ch,ele,n,xxx;
  do
  {
      printf("\nenter choice\n1:insert\n2:delete\n3:display\n4:Search\n0:Exit\n\tCHOICE :- ");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:
          printf("\n enter no of elements to insert :- ");
          scanf("%d",&n);
          for(int i=0;i<n;i++)
          {
          printf("\n enter element :- ");
          scanf("%d",&ele);
          root = insert(root,ele);
          }
          break;
          case 2:
          printf("\n enter element :- ");
          scanf("%d",&ele);
          root = deleteNode(root, ele);
          break;
          case 3:
          printf("Inorder traversal:- ");
          inorder(root);
          break;
          case 4:
          printf("\nEnter the number to search");
          scanf("%d",&xxx);
          search(root,xxx);
          break;
          case 0:
          printf("program terminated...!!!");
          break;
          default:
          printf("wrong input");
      }
          
      
  }while(ch!=0);
 
}