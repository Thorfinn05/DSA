#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int i, front=-1, rear=-1;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *root=NULL;
struct Node *queue[MAX];

// struct Node *create(int val){
//   struct Node *new;
//   new=malloc(sizeof(struct Node));
//   new->data=val;
//   new->left=NULL;
//   new->right=NULL;
//   return new;
// }

// struct Node *insert(struct Node *root, int val){
//   if(root==NULL){
//     root=create(val);
//     return root;
//   }
//   if(val<root->data){
//     root->left=insert(root->left, val);
//   }
//   else if(val>root->data){
//     root->right=insert(root->right, val);
//   }
// }

struct Node *create(){
  struct Node *node;
  node=malloc(sizeof(struct Node));
  int ans, data;
  printf("\nPress 1 to create a new node or 0 to exit/skip: ");
  scanf("%d", &ans);
  if(ans==0){
    return NULL;
  }
  printf("Enter data: ");
  scanf("%d", &data);
  node->data=data;
  printf("Enter left/right node of %d ->", data);
  if(data < node->data){
    node->left=create();
    printf("%d entered at left node of %d",data, node->data);
  }
  else if(data > node->data){
    node->right=create();
    printf("%d entered at right node of %d",data, node->data);
  }
  return node;
}

void inorder(struct Node *root){
  if(root!=NULL){
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
  }
}

int main(){
  int choice, val;
  printf("\nChoose:\n1. Insert\n2. Exit\n3. Inorder");
  while(1){
    printf("\nEnter Choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        root=create();
        break;
      case 2:
        printf("Exiting...\n");
        break;
      case 3:
        inorder(root);
        break;
      default:
        printf("Invalid Input!\n");
        break;
    }
  }
}