#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};
// ***[MAKES THE CODE LONGER SO USING SHORT VERSION]***
// struct Node *create(int data){
//   struct Node *node=(struct Node*)malloc(sizeof(struct Node));
//   node=malloc(sizeof(struct Node));
//   node->data=data;
//   node->left=NULL;
//   node->right=NULL;
//   return node;
// }

// struct Node *insert(){
//   int c, data;
//   printf("\nPress 1 to create new node or 0 to exit:");
//   scanf("%d",&c);
//   if(c==0){
//     return NULL;
//   }
//   printf("Enter data: ");
//   scanf("%d",&data);
//   struct Node *node=create(data);
//   printf("Enter left child of %d", data);
//   node->left=insert();
//   printf("Enter right child of %d", data);
//   node->right=insert();

//   return node;
// }

struct Node *create(){
  struct Node *node;
  node=malloc(sizeof(struct Node));
  int cho, data;
  printf("\nPress 1 to create a new node or 0 to exit:");
  scanf("%d", &cho);
  if(cho==0){
    return NULL;
  }
  printf("Enter data");
  scanf("%d", &data);
  node->data=data;
  printf("Enter left node of %d ->", data);
  node->left=create();
  printf("Enter right node of %d ->", data);
  node->right=create();
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

int height(struct Node *root){
  int lheight, rheight;
  if(root==NULL){
    return 0;
  }
  else{
    lheight=height(root->left);
    rheight=height(root->right);
    if(lheight>rheight){
      return lheight++;
    }
    else{
      return rheight++;
    }
  }
}

int main(){
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
        
        root=insert();
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