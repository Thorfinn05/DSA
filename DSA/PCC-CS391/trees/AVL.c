#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};

struct Node *createNode(int val){
  struct Node* new;
  new=malloc(sizeof(struct Node));
  new->data=val;
  new->left=NULL;
  new->right=NULL;
  new->height=1;
}

int height(struct Node *root){
  if(root==NULL){
    return 0;
  }
  return root->height;
}

int getbf(struct Node *root){
  if(root==NULL){
    return 0;
  }
  return height(root->left)-height(root->right);
}

int max(int a, int b){
    return a>b?a:b;
}

struct Node* rightRotate(struct Node *y){
  struct Node *x=y->left;
  struct Node *T2=x->right;

  x->right=y;
  y->left=T2;

  y->height=1+max(height(y->left),height(y->right));
  x->height=1+max(height(x->left), height(x->right));

  return x;
}

struct Node *leftRotate(struct Node *x){
  struct Node *y=x->right;
  struct Node *T2=y->left;

  y->left=x;
  x->right=T2;

  x->height=1+max(height(x->left), height(x->right));
  y->height=1+max(height(y->left), height(y->right));

  return y;
}

struct Node *insert(struct Node *root, int val){
  if(root==NULL){
    return createNode(val);
  }

  if(val< root->data){
    root->left=insert(root->left, val);
  }
  else if(val > root->data){
    root->right=insert(root->right, val);
  }
  else 
    return root;

  root->height=1+max(height(root->left), height(root->right));
  int bf=getbf(root);

  if(bf>1 && val<root->left->data){
    return rightRotate(root);
  }
  if(bf<-1 && val>root->right->data){
    return leftRotate(root);
  }
  if(bf>1 && val>root->left->data){
    root->left=leftRotate(root->left);
    return rightRotate(root);
  }
  if(bf<-1 && val<root->right->data){
    root->right=rightRoate(root->right);
    return leftRotate(root);
  }
  return root;
}

void preorder(struct Node *root){
  if(root!=NULL){
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(struct Node *root){
  if(root!=NULL){
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
  }
}

void postorder(struct Node *root){
  if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
  }
}

int main(){
  struct Node *root=NULL;
  int choice, val;
  while(1){
    printf("\nChoose:\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter value to insert: ");
        scanf("%d", &val);
        root=insert(root, val);
        break;
      case 2:
        preorder(root);
        break;
      case 3:
        inorder(root);
        break;
      case 4:
        postorder(root);
        break;
      case 5:
        printf("Exiting...");
        return 0;
      default:
        printf("Invalid choice!");
    }
  }
  return 0;
}