#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;
int size=0, s=0;

void insert(int val){
  if(s==size){
    printf("Overflow!");
    return;
  }
  else{
    struct Node *new, *ptr;
    new=malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    if(front==NULL && rear==NULL){
      front=rear=new;
    }
    else{
      rear->next=new;
      rear=new;
    }
    s++;
    printf("Inserted.");
  }
}

void delete(){
  struct Node *ptr;
  if(front==NULL){
    printf("Underflow!");
  }
  else{
    ptr=front;
    front=front->next;
    free(ptr);
    s--;
    printf("Deleted.");
  }
}

void display(){
  struct Node *ptr;
  ptr=front;
  printf("Queue: ");
  while(ptr!=NULL){
    printf("\n%d",ptr->data);
    ptr=ptr->next;
  }
}

int main(){
  int val, choice, n;
  printf("Enter Queue size: ");
  scanf("%d",&size);
  while(1){
    printf("\nChoose:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter Choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter element: ");
        scanf("%d",&val);
        insert(val);
        break;

      case 2:
        delete();
        break;

      case 3:
        display();
        break;

      case 4:
        printf("Exiting...");
        return 0;

      default:
        printf("Invalid Input!");
    }
  }
}