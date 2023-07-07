//BST
//8, 3, 10 -- node
//1, 6, 14, 4, 7 -- insert
//3 -- delete


#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
}node;

node *cnode(int a)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=a;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

node *inode(node *root, int a)
{
    if(root==NULL)
        return cnode(a);
    if(a<root->data)
        root->left=inode(root->left,a);
    else
        root->right=inode(root->right,a);
    return root;
}

node *createtree(node *root,int a,int b, int c)
{
    root=inode(root,a);
    root=inode(root,b);
    root=inode(root,c);
   
    return root;
}
void displaycreate(node *u)
{
    
     printf("\nInorder: ");
    inorder(u);
    printf("\nPreorder: ");
    preorder(u);
    printf("\nPostorder: ");
    postorder(u);
    printf("\n");

}

node *successor(node *root)
{
    node *current=root;
    while(current && current->left!=NULL)
        current=current->left;
    return current;
}

node *dnode(node *root, int key)
{
  if (root == NULL) 
      return root;
  if (key < root->data)
    root->left=dnode(root->left, key);
  else if (key > root->data)
    root->right=dnode(root->right, key);
  else 
  {
    if (root->left == NULL) 
    {
        node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) 
    {
        node *temp = root->left;
        free(root);
        return temp;
    }
    else
    {
        node *temp = successor(root->right);
        free(root->right);
        inode(root,temp->data);
    }
  }
  return root;
}

void insertnode(node *root,int a)
{
    root=inode(root,a);
   
}
void displayins(node *v)
{
    
     printf("\nInorder: ");
    inorder(v);
    printf("\nPreorder: ");
    preorder(v);
    printf("\nPostorder: ");
    postorder(v);
    printf("\n");

}

void deletenode(node *root,int a)
{
    root=dnode(root,a);
    
}
void displaydel(node *w)
{
    
    printf("\nInorder: ");
    inorder(w);
    printf("\nPreorder: ");
    preorder(w);
    printf("\nPostorder: ");
    postorder(w);
    printf("\n");

}

void main()
{
    node *root=NULL;
    root=createtree(root,8,3,10);
    displaycreate(root);
    insertnode(root,1);
    displayins(root);
    insertnode(root,6);
    displayins(root);
    insertnode(root,14);
    displayins(root);
    insertnode(root,4);
    displayins(root);
    insertnode(root,7);
    displayins(root);
    deletenode(root,3);
     displaydel(root);
}