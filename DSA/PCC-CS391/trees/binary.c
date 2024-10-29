#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node *left;
  struct Node *right;
};
struct Node *root=NULL;

struct Node *create(){
  struct Node *new;
  int val;
  new=malloc(sizeof(struct Node));
  printf("Enter data(if no data put -1): ");
  scanf("%d",&val);
  new->data=val;
  if(val==-1){
    return NULL;
  }
  printf("Enter the left Node")
}