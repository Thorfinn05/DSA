#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *create(int data, struct Node *node){
  node=malloc(sizeof(struct Node));
  node->data=data;
  // node->left=NULL;
  // node->right=NULL;
  return node;
}

struct Node *insert(struct Node *node){
  int c, data;
  printf("\nPress 1 to create new node or 0 to exit:");
  scanf("%d",&c);
  if(c==0){
    return NULL;
  }
  printf("Enter data: ");
  scanf("%d",&data);
  node=create(data, node);
  printf("Enter left child: %d", data);
  node->left=create(data, node);
  printf("Enter right child: %d", data);
  node->right=create(data, node);

  return node;
}

void preorder(struct Node *root){
  if(root!=NULL){
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct Node *root){
  if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

void inorder(struct Node *root){
  if(root!=NULL){
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main(){
  struct Node *node;
  struct Node *root=NULL;
  int choice, data, c;
  printf("\nChoose:\n1. Insert\n2. Exit\n3. Preorder\n4. Postorder\n5. Inorder");
  while(1){
    printf("\nEnter choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        // printf("Enter element to insert: ");
        // scanf("%d",&data);
        //   // printf("Which Node? (Left/Right): ");
        //   // scanf("%d",&c);
        //   // if(c=1){
        //   //   root->left=insert(root, data, c);
        //   //   break;
        //   // } 
        //   // else if(c=2){
        //   //   root->right=insert(root, data, c);
        //   //   break;
        //   // }
        //   // else{
        //   //   root->left=NULL;
        //   //   root->right=NULL;
        //   //   break;
        //   // }
        
        root=insert(node);
        break;
      case 2:
        printf("Exiting...");
        return 0;
      case 3:
        preorder(root);
        break;
      case 4:
        postorder(root);
        break;
      case 5:
        inorder(root);
        break;
      default:
        printf("Invalid Input!\n");
    }
  }
}