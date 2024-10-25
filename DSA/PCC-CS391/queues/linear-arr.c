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
    for(i=0; i<n; i++){
      scanf("%d",&val);
      rear++;
      queue[rear]=val;
    }
    printf("Inserted.\n");
  }
}

void delete(){
  if(front==-1 || front>rear){
    printf("Underflow!\n");
  }
  else{
    int val=queue[rear];
    front++;
    printf("Deleted.\n");
  }
}

void display(){
  printf("Queue: \n");
  for(i=front+1; i<=rear; i++){
    printf("%d",queue[i]);
  }
  if(front==-1 && rear==-1){
    printf("Empty Queue!\n");
  }
}

int main(){
  printf("Enter population: ");
  scanf("%d",&n);
  while(1){
    printf("\nChoose:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter Choice: ");
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