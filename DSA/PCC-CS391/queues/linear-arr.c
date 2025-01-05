#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[20];
int i, n, choice, front=-1, rear=-1;

void insert(){
  int val;
  if(rear==n-1){
    printf("Overflow!\n");
  }
  else{
    printf("Enter elements: ");
    scanf("%d",&val);
    if(front==-1 && rear==-1){
      front=0; rear=0;
      queue[rear]=val;
    }
    else{
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
    front++;
    printf("Deleted.\n");
  }
}

void display(){
  if(front==-1 || front>rear){
    printf("Underflow!(Empty Queue!)\n");
  }
  else{
    printf("Queue: \n");
    for(i=front; i<=rear; i++){
      printf("%d\n",queue[i]);
    }
  }
}

void peek(){
  printf("Peeked. Front: %d",queue[front]);
}

int main(){
  printf("Enter n: ");
  scanf("%d", &n);
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