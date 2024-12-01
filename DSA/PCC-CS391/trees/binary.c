#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *root=NULL;

struct Node *create(int data){
  root=malloc(sizeof(struct Node));
  root->data=data;
  root->left=NULL;
  root->right=NULL;
  return root;
}

struct Node *insert(int data, int c){
  if(root==NULL){
    root=create(data);
  }
  else{
    // printf("Which Node? (Left/Right): ");
    // scanf("%d",&c);
    // if(c=1){
    //   root->left=insert(data, c);
    // } 
    // else if(c=2){
    //   root->right=insert(data, c);
    // }
    // else{
    //   root->left=NULL;
    //   root->right=NULL;
    // }
  }
  
  return root;
}

void preorder(){
  if(root!=NULL){
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(){
  if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

void inorder(){
  if(root!=NULL){
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main(){
  int choice, data, c;
  printf("\nChoose:\n1. Insert\n2. Exit\n3. Preorder\n4. Postorder\n5. Inorder");
  while(1){
    printf("\nEnter choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        printf("Enter element to insert: ");
        scanf("%d",&data);
          printf("Which Node? (Left/Right): ");
          scanf("%d",&c);
          if(c=1){
            root->left=insert(data, c);
            break;
          } 
          else if(c=2){
            root->right=insert(data, c);
            break;
          }
          else{
            root->left=NULL;
            root->right=NULL;
            break;
          }
        
        insert(data, c);
        break;
      case 2:
        printf("Exiting...");
        return 0;
      case 3:
        preorder();
        break;
      case 4:
        postorder();
        break;
      case 5:
        inorder();
        break;
      default:
        printf("Invalid Input!\n");
    }
  }
}