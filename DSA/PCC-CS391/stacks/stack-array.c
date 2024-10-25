#include<stdio.h>

int stack[100], i, choice, n, top=-1;

void create(){
  int val;
  if(top==n){
    printf("Overflow.\n");
  }
  else{
    printf("Enter elements: ");
    for(i=0; i<n; i++){
      scanf("%d",&val);
      top++;
      stack[top]=val;
    }
    printf("Element pushed.\n");
  }
}

void push(){
  int val;
  if(top==n){
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
    top--;
    printf("Element popped.\n");
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
    printf("\nChoose:\n1. Create\n2. Push\n3. Pop\n4. Dispaly\n5. Exit\nEnter Choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        create();
        break;
      case 2:
        push();
        break;
      case 3:
        pop();
        break;
      case 4:
        display();
        break;
      case 5:
        printf("Exiting...");
        return 0;
      default:
        printf("Invalid Input!\n");
    }
  }
}