#include <stdio.h>  
#include <stdlib.h>  

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL;

struct Node *createNode(int val){
    struct Node *new; 
    new = malloc(sizeof(struct Node));
    new->data=val;
    new->left=NULL;
    new->right=NULL;
    return new;
}
 
struct Node *search(struct Node *root, int val){  
    if (root == NULL || val == root->data)
        return root;  
    else if (val > root->data)
        return search(root->right, val);  
    else
        return search(root->left, val);  
}  

//searching in bst by iteration (no recursion used)
struct Node *searchIter(struct Node *root, int val){
    while (root!=NULL){
        if(val == root->data)
            return root;
        else if(val < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

void inorder(struct Node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);    
}

void insert(struct Node *root, int val){
    struct Node *prev = NULL;
    struct Node *new = createNode(val);
    while(root!=NULL){
        prev = root;
        if(val == root->data){
            printf("Cannot insert %d already in BST!", val);
            return;
        }
        else if(val < root->data)
            root = root->left;
        else
            root = root->right;
    }
    if(val < prev->data)
        prev->left = new;
    else
        prev->right = new;
}

struct Node *insertrec(struct Node *root, int val){
    if(root==NULL)
        return createNode(val);
    else if(val < root->data)
        root->left = insertrec(root->left,val);
    else
        root->right = insertrec(root->right,val);   
    return root;
}

struct Node *inorderPrev(struct Node *root){
    root = root->left;
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

struct Node *delete(struct Node *root, int val){
    struct Node *iPrev;
    if(root == NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(val < root->data){
        root->left = delete(root->left, val);
    }
    else if(val > root->data){
        root->right = delete(root->right, val);
    }
    else{
        iPrev = inorderPrev(root); //inorder predecessor
        root->data = iPrev->data;
        root->left = delete(root->left, iPrev->data);
    }
    return root;
}

struct Node *smallest(struct Node *root){
    if(root==NULL||root->left==NULL)
        return root;
    else
        return smallest(root->left);
}

struct Node *largest(struct Node *root){
    if(root==NULL||root->right==NULL)
        return root;
    else
        return largest(root->right);
}
  
int main(){
    int choice, val, ans=1;
    while (1) {
        printf("\nChoose:\n1.Create\n2.Inorder\n3.Search\n4.Insert\n5.Delete\n6.Smallest\n7.Largest\n8.Quit\nEnter choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter root:");
                scanf("%d",&val);
                root = createNode(val);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                printf("Enter data to search:");
                scanf("%d",&val);
                if(search(root,val))
                    printf("%d in tree",val);
                else
                    printf("%d not in tree",val);
                break;
            case 4:
                while(ans==1){
                    printf("Enter data to insert:");
                    scanf("%d",&val);
                    // insert(root, val);
                    root=insertrec(root,val);
                    printf("\nPress 1 to insert new node or 0 to exit:");
                    scanf("%d", &ans);
                }
                break;
            case 5:
                printf("Enter data to delete:");
                scanf("%d",&val);
                delete(root,val);
                break;
            case 6:
                printf("Smallest node is %d", smallest(root)->data);
                break;
            case 7:
                printf("Largest node is %d", largest(root)->data);
                break;
            case 8:
                printf("Bye bye");
                return 0; 
                break;
            default:
                printf("Invalid Input\n");
        }
    }
}