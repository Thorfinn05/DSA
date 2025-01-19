#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
  if(top==MAX-1){
    printf("Overflow!\n");
    return;
  }
  stack[++top]=symbol;
}

void pop(){
   if(top==-1){
    printf("Underflow!\n");
    return;
  }
  stack[top--];
}

int evaluatePostfix(char* postfx){
  int i;
  for (i=0; postfix[i]!='\0'; i++){
    char symbol=postfix[i];

    if(isdigit(symbol)){
      push(symbol - '0');
    }
    else{
      int op1=pop();
      int op2=pop();
      switch(symbol){
        case '+': push(op1+op2); break;
        case '-': push(op1-op2); break;
        case '*': push(op1*op2); break;
        case '/': if(op2!=0) {push(op1/op2);} break;
        case '%': push(op1%op2); break;
        case '^': 
          int res=1;
          for(int j=0; j<op2; j++){
            res*=op1;
          } push res; break;
        default: printf("Invalid operator: %c\n", symbol); return -1;
      }
    }
  }
  return pop();
}

int main(){
  char postfix[MAX];
  printf("Enter a postix expression: ");
  scanf("%s", &postfix);

  int result = evaluatePostfix(postfix);
  if(result!=-1){
    printf("The result of evaluation of postfix expression: %d",result);
  }
  return 0;
}
  
