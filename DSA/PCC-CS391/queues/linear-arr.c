#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int i, n, choice, front=-1, rear=-1;

void insert(){
  int val;
  if(rear==MAX-1){
    printf("Overflow!\n");
  }
  else{
    if(front==-1 && rear==-1){
      front=0; rear=0;
    }
    printf("Enter elements: ");
      scanf("%d",&val);
      rear++;
      queue[rear]=val;
    printf("Inserted.\n");
  }
}

void delete(){
  if(front==-1 || front>rear){
    printf("Underflow!\n");
  }
  else{
    front++;
    printf("Deleted.\n");
  }
}

void display(){
  printf("Queue: \n");
  for(i=front+1; i<=rear; i++){
    printf("%d\n",queue[i]);
  }
  if(front==-1 || front>rear){
    printf("Empty Queue!\n");
  }
}

void peek(){
  printf("Front: %d",queue[front+1]);
}

int main(){
  printf("Enter population: ");
  scanf("%d",&n);
  printf("\nChoose:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n5. Peek");
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
      case 5:
        peek();
        break;
      default:
        printf("Invalid Input!\n");
    }
  }
}