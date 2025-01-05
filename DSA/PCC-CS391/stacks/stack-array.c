#include<stdio.h>

int stack[100], i, choice, n, top=-1;

void push(){
  int val;
  if(top==n-1){
    printf("Overflow.\n");
  }
  else{
    printf("Enetr element to push: ");
    scanf("%d", &val);
    top++;
    stack[top]=val;
    printf("Element pushed.\n");
  }
}

void pop(){
  if(top==-1){
    printf("Underflow.\n");
  }
  else{
    printf("Element %d popped.\n", stack[top]);
    top--;
  }
}

void peek(){
  if(top==-1){
    printf("Underflow!\n");
  }
  else{
    printf("Peeked. Top element is %d.\n", stack[top]);
  }
}
void display(){
  printf("Stack: ");
  for(i=top; i>=0; i--){
    printf("%d\n",stack[i]);
  }
  if(top==-1){
    printf("Stack empty!");
  }
}

int main(){
  printf("Enter n: ");
  scanf("%d", &n);
  while(1){
    printf("\nChoose:\n1. Push\n2. Pop\n3. Dispaly\n4. Exit\n5. Peek\nEnter Choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Exiting...");
        return 0;
      case 5:
        peek();
        break;
      default:
        printf("Invalid Input!\n");
    }
  }
}