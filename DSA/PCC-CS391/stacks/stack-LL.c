#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};
struct Node *top=NULL;

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
    printf("Underflow!\n");
  }
  else{
    printf("Element %d popped!\n", ptr->data);
    top=ptr->next;
    free(ptr);
  }
}

void peek(){
  struct Node *ptr=top;
  if(top==NULL){
    printf("Stack is empty!\n");
  }
  else{
    printf("Peeked. The top element in the stack is %d.\n",ptr->data);
  }
}

void display(){
  struct Node *ptr=top;
  printf("Stack:\n");
  while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
  }
}

int main(){
  int choice, val;
  while(1){
    printf("*Choose*\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        printf("Enter element to push: ");
        scanf("%d",&val);
        push(val);
        printf("Element pushed.\n");
        break;
      case 2:
        pop();
        break;
      case 3:
        peek();
        break;
      case 4:
        display();
        break;
      case 5:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid Input.\n");
    }
  }
}