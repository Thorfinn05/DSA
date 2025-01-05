#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *root=NULL;
struct Node *queue[MAX];

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
  int choice, data;
  printf("\nPress 1 to create a new node or 0 to exit:");
  scanf("%d", &choice);
  if(choice==0){
    return NULL;
  }
  printf("Enter data: ");
  scanf("%d", &data);
  node->data=data;
  printf("Enter left node of %d ->", data);
  node->left=create();
  printf("Enter right node of %d ->", data);
  node->right=create();
  return node;
}

int i, front=-1, rear=-1;

void insert(struct Node *data){
  if(rear==MAX-1){
    printf("Overflow!\n");
  }
  else{
    if(front==-1 && rear==-1){
      front=rear=0;
    }
    else{
      rear++;
    }
    queue[rear]=data;
  }
}

int isEmpty(){
  if(front==-1 || front>rear){
    return 1;
  }
  else{
    return 0;
  }
}

struct Node *delete(){
  if(isEmpty()==1){
    printf("Underflow!\n");
  }
  else{
    struct Node *data;
    data=queue[front];
    front++;
    return data;
  }
}

void levelorder(struct Node *root){
  struct Node *ptr;
  insert(root); //inserting the root element in the queue
  while(isEmpty()==0){
    ptr=delete(); //after deleting the front element from the queue; (ptr = deleted element)
    if(ptr->left!=NULL){
      insert(ptr->left);
    }
    if(ptr->right!=NULL){
      insert(ptr->right);
    }
    printf("%d ", ptr->data); //the front elemnt of the queue which was deleted now printed in the output
  }
}

/* Example: Root was 70 and it had two child, left 60 right 80.
Root was inserted in the queue and as it was the front element after deleting it in "ptr=delete()" step the front element is coming back as data was returned and now "ptr=deleted front element=70".
70's left and right child enqueud...queue=[60, 80].
As 60 is the front it is deleted and now 80 is the new front while the queue have the left and right child of 60 after 80 say, 30 and 62 and current queue is...queue=[80, 30, 62].
The process is continued till there's no element is left. */

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
      return ++lheight;
    }
    else{
      return ++rheight;
    }
  }
}

int totalNodes(struct Node *root){
  if(root==NULL){
    return 0;
  }
  else{
    return (totalNodes(root->left)+totalNodes(root->right)+1);
  }
}

int totalIntNodes(struct Node *root){
  if(root==NULL || root->left==NULL && root->right==NULL){
    return 0;
  }
  else{
    return (totalIntNodes(root->left)+totalIntNodes(root->right)+1);
  }
}

int totalExtNodes(struct Node *root){
  if(root==NULL){
    return 0;
  }
  else if((root->left==NULL) && (root->right==NULL)){
    return 1;
  }
  else{
    return (totalExtNodes(root->left)+totalExtNodes(root->right));
  }
}

void mirror(struct Node *root){
  struct Node *temp;
  if(root!=NULL){
    mirror(root->left);
    mirror(root->right);
    temp=root->left;
    root->left=root->right;
    root->right=temp;
  }
}

void removeTreeMem(struct Node *root){
  if(root!=NULL){
    removeTreeMem(root->left);
    removeTreeMem(root->right);
    free(root);
  }
}

int checkBST(struct Node *root){
  static struct Node *prev=NULL;
  if(root!=NULL){
    if(!checkBST(root->left)){
      return 0;
    }
    if(prev!=NULL && root->data <= prev->data){
      return 0;
    }
    prev=root;
    return checkBST(root->right);
  }
  return 1;
}

int main(){
  int choice, data, c;
  printf("\nChoose:\n1. Insert\n2. Exit\n3. Preorder\n4. Postorder\n5. Inorder\n6. Levelorder\n7. Height\n8. Totoal Nodes\n9. Total Internal Nodes\n10. Total External Nodes\n11. Mirror Tree\n12. Remove Tree from Memory\n13. Check BST");
  while(1){
    printf("\nEnter choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        root=create();
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
      case 6:
        levelorder(root);
        break;
      case 7:
        printf("Height of the Tree is %d", height(root));
        break;
      case 8:
        printf("Total no. of nodes is %d", totalNodes(root));
        break;
      case 9:
        printf("Total no. of internal(non-leaf) nodes is %d", totalIntNodes(root));
        break;
      case 10:
        printf("Total no. of external(leaf) nodes is %d", totalExtNodes(root));
        break;
      case 11:
        mirror(root);
        break;
      case 12:
        removeTreeMem(root);
        break;
      case 13:
        checkBST(root);
        break;
      default:
        printf("Invalid Input!\n");
    }
  }
}