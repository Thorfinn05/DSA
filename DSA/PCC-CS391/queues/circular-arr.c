#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int i, choice, front=-1, rear=-1;

void insert(){
  int val;
  if((front==0 && rear==MAX-1) || rear==front-1){
    printf("Overflowed!");
  }
  else{
    printf("Eneter elements: ");
    scanf("%d",&val);
    if(front==-1 && rear==-1){
      front=0; rear=0;
    }
    else if(front!=0 && rear==MAX-1){
      rear=0;
    }
    else{
      rear++;
    }
    queue[rear]=val;
    printf("Inserted.\n");
  }
}

void delete(){
  if(front==-1 && rear==-1){
    printf("Underflow!\n");
  }
  else{
    if(front==MAX-1 && rear!=front){
      front=0;
    }
    else if(front==rear){
      front=-1; rear=-1;
    }
    else{
      front++;
    }
    printf("Deleted.\n");
  }
}

void display(){
  if(front==-1 && rear==-1){
    printf("Empty Queue!\n");
  }
  else{
    printf("Queue: \n");
    if(rear>=front){
      for(i=front+1; i<=rear; i++){
        printf("%d\n",queue[i]);
      }
    }
    else{
      for(i=front; i<=MAX-1; i++){
        printf("%d\n",queue[i]);
      }
      for(i=0; i<=rear; i++){
        printf("%d\n",queue[i]);
      }
    }
  }
}

int main(){
  printf("\nChoose:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
  while(1){
    printf("\nEnter Choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        insert();
        break;
      case 2:
        delete();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid Input!\n");
    }
  }
}