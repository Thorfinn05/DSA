#include <stdio.h>
#define MAX 5

int deque[MAX];
int front=-1, rear=-1;

int full(){
  return (front==0 && rear==MAX-1) || (rear==(front-1)%(MAX-1));
}

int empty(){
  return front==-1;
}

void insertRear(int val){
  if(full()){
    printf("Deque is full!\n");
    return;
  }
  if(empty()){
    front=rear=0;
  }
  else if(rear==MAX-1){
    rear=0;
  }
  else{
    rear++;
  }
  deque[rear]=val;
  printf("%d inserted at rear.\n",val);
}

void insertFront(int val){
  if(full()){
    printf("Deque is full!\n");
    return;
  }
  if(empty()){
    front=rear=0;
  }
  else if(front==0){
    front=MAX-1;
  }
  else{
    front--;
  }
  deque[front]=val;
  printf("%d inserted at front.\n",val);
}

void deleteRear(){
  if(empty()){
    printf("Deque is empty!\n");
    return;
  }
  printf("%d deleted from rear.\n",deque[rear]);
  if(front==rear){
    front=rear=-1;
  }
  else if(rear==0){
    rear=MAX-1;
  }
  else{
    rear--;
  }
}

void deleteFront(){
  if(empty()){
    printf("Deque is empty!\n");
    return;
  }
  printf("%d deleted from front.\n",deque[front]);
  if(front==rear){
    front=rear=-1;
  }
  else if(front==MAX-1){
    front=0;
  }
  else{
    front++;
  }
}

void display(){
  if(empty()){
    printf("Deque is empty!\n");
    return;
  }
  printf("Deque: \n");
  int i=front;
  if(front<=rear){
    while(i<=rear){
      printf("%d\t",deque[i]);
      i++;
    }
  }
  else{
    while(i<MAX){
      printf("%d\t",deque[i]);
      i++;
    }
    i=0;
    while(i<=rear){
      printf("%d\t",deque[i]);
      i++;
    }
  }
  printf("\n");
}

int main(){
  int choice, val;
  while(1){
    printf("\nDeque Operations:\n1. Insert at Rear\n2. Insert at Front\n3. Delete from Rear\n4. Delete from front\n5. Display\n6. Exit\nEnter Choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        printf("Enter element to insert: ");
        scanf("%d",&val);
        insertRear(val);
        break;
      case 2:
        printf("Enter element to insert: ");
        scanf("%d",&val);
        insertFront(val);
        break;
      case 3:
        deleteRear();
        break;
      case 4:
        deleteFront();
        break;
      case 5:
        display();
        break;
      case 6:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid Input!\n");
    }
  }
}