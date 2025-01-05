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
  stack[++top] = c;
}

char pop(){
  if(top == -1){
    printf("Underflow!\n");
    return -1;
  }
  return stack[top--];
}

int precedence(char c){
  if(c == '^') return 3;
  if(c == '*' || c == '/' || c == '%') return 2;
  if(c == '+' || c == '-') return 1;
  return 0;
}

int isOperator(char c){
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

void infixToPostfix(char* infix, char* postfix){
  int i, j = 0;
  for(i=0; i<strlen(infix); i++){
    char symbol = infix[i];

    if(isalnum(symbol)){
      postfix[j++]=symbol;
    }

    else if(symbol=='('){
      push(symbol);
    }

    else if(symbol==')'){
      while(top!=-1 && stack[top]!='('){
        postfix[j++]=pop();
      }
      pop();
    }

    else if(isOperator){
      while(top!=-1 && precedence(stack[top])>=precedence(symbol)){
        postfix[j++]=pop();
      }
      push(symbol);
    }
  }

  while(top!=-1){
    postfix[j++]=pop();  
  }
  postfix[j]='\0';
}

int main(){
  char infix[MAX], postfix[MAX];
  printf("Enter an infix expression: ");
  scanf("%s", infix);

  infixToPostfix(infix, postfix);
  printf("postfix Expression: %s\n", postfix);

  return 0;
}