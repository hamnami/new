#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*left;
  struct node*right;
}*newnode,*temp,*root;

void create();
void insert(struct node*,struct node*);

void create()
{
  int ele;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->left=NULL;
  newnode->right=NULL;
  printf("enter the data:");
  scanf("%d",&ele);
  newnode->data=ele;
  if(root==NULL)
  {
    root=newnode;
  }
  else
  {
    insert(root,newnode);
  }
}
 void insert(struct node*root,struct node*newnode)
{
     if(newnode->data<root->data)
     {
        if(root->left==NULL)
              {
                root->left=newnode;
              }
              else
              {
                insert(root->left,newnode);
              }
     
     }
     else
     {
        if(root->right==NULL)
              {
                 root->right=newnode;
              }
              else
              {
                 insert(root->right,newnode);
              }
        
     }
        
}
struct node*find_min(struct node*root)
{
   if(root==NULL)
   {
      return root;
    }
    else if(root->left==NULL)
    {
        return root;
    }
     else                                         //left node is there
     {
         return find_min(root->left);
      }
 }
struct node*delete(struct node*root,int value)
{
   if(root==NULL)
   {
     return root;
   }
   else if(value<root->data)
   {
      root->left=delete(root->left,value);
   }
   else if(value>root->data)                         
   {
       root->right=delete(root->right,value);
    }
    else
    {
         if(root->left==NULL && root->right==NULL)       //leaf node
         {
              root=NULL;
              free(root);
          }
          else if(root->left==NULL)                     //right child only
          {
             temp=root;
             root=root->right;
             free(temp);
          }
          else if(root->right==NULL)                      //left child only
          {
               temp=root;
               root=root->left;
               free(temp);
          }
          else
          {
             
             temp=find_min(root->right);
             root->data=temp->data;
             root->right=delete(root->right,temp->data);
           }
            return root;
     }  
 }
struct node*search(struct node*root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(key==root->data)
    {
       return root;
     }
     else if(key<root->data)
     {
          search(root->left,key);
     }
     else if(key>root->data)
     {
         search(root->right,key);
     }
}
void main()
{
  
  int value,key,ch;
  printf("Binary tree operations:\n1.insert\n2.delete\n3.search\n4.exit\n");
  do
  {
     printf("Enter your choice:");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1:
                 create();
                 break;
         case 2:
                printf("enter the value to be delete:");
                scanf("%d",&value);
                root=delete(root,value);
		printf("%d deleted from bst..\n",value);
		break;
         case 3:
                 printf("enter the value to be search:");
                 scanf("%d",&key);
                 if(search(root,key)!=NULL)
		 {
			printf("%d found in bst!\n",key);
		 }
		 else
		 {
			printf("%d not found in bst!\n",key);
		 }
		 break;
         default:
                printf("INVALID CHOICE");
      }
   }while(ch!=4);
}
               
        
