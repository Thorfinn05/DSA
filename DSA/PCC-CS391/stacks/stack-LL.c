#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};
struct Node *top=NULL;

void create(int val){
  struct Node *new, *ptr;
  new=malloc(sizeof(struct Node));
  new->data=val;
  new->next=NULL;
  if(top==NULL){
    top=new;
  }
  else{
    new->next=top;
    top=new;
  }
}

void push(int val){
  struct Node *new, *ptr;
  new=malloc(sizeof(struct Node));
  new->data=val;
  new->next=NULL;
  if(top==NULL){
    top=new;
  }
  else{
    new->next=top;
    top=new;
  }
}

void pop(){
  struct Node *ptr=top;
  if(top==NULL){
    printf("Underflow.\n");
  }
  else{
    top=ptr->next;
    free(ptr);
    printf("Element popped.\n");
  }
}

void peek(int val){
  struct Node *ptr=top;
  if(ptr->data=val){
    printf("Element %d is on top.", val);
  }
  else{
    printf("Element %d is not on top.", val);
  }
}

void display(){
  struct Node *ptr=top;
  printf("Stack: ");
  while(ptr!=NULL){
    printf("\n%d\n",ptr->data);
    ptr=ptr->next;
  }
}

int main(){
  int choice, val, n;
  while(1){
    printf("*Choose*\n1. Create\n2. Push\n3. Pop\n4. Peek\n5. Display\n6. Exit\nEnter choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1: 
        printf("Enter population: ");
        scanf("%d",&n);
        int i;
        printf("Enter elements: ");
        for(i=0;i<n;i++){
          scanf("%d",&val);
          create(val);
        }
        break;
      case 2:
        printf("Enter element to push: ");
        scanf("%d",&val);
        push(val);
        printf("Element pushed.\n");
        break;
      case 3:
        pop();
        break;
      case 4:
        printf("Enter element to peek: ");
        scanf("%d",&val);
        peek(val);
        break;
      case 5:
        display();
        break;
      case 6:
        printf("Exiting...");
        return 0;
      default:
        printf("Invalid Input.\n");
    }
  }
}