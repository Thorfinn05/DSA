#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
  if(top == MAX-1){
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

void reverse(char* exp){
  int n = strlen(exp);
  for(int i = 0; i < n/2; i++){
    char temp = exp[i];
    exp[i] = exp[n-i-1];
    exp[n-i-1] = temp;
  }
}

void infixToPrefix(char* infix, char* prefix){
  int i, j = 0;
  char temp[MAX], postfix[MAX];

  // Step 1: Reverse the infix expression
  strcpy(temp, infix);
  reverse(temp);
  
  for(i = 0; i < strlen(temp); i++){
    if(temp[i] == '(')
      temp[i] = ')';
    else if(temp[i] == ')')
      temp[i] = '(';
  }

  // Step 2: Convert to postfix
  for(i = 0; i < strlen(temp); i++){
    char symbol = temp[i];

    if(isalnum(symbol)){
      postfix[j++] = symbol;
    }
    else if(symbol == '('){
      push(symbol);
    }
    else if(symbol == ')'){
      while(top != -1 && stack[top] != '('){
        postfix[j++] = pop();
      }
      pop();
    }
    else if(isOperator(symbol)){
      while(top != -1 && precedence(stack[top]) >= precedence(symbol)){
        postfix[j++] = pop();
      }
      push(symbol);
    }
  }
  while(top != -1){
    postfix[j++] = pop();
  }
  postfix[j] = '\0';

  // Step 3: Reverse the postfix expression
  strcpy(temp, postfix);
  reverse(temp);
  strcpy(prefix, temp);
}

int main(){
  char infix[MAX], prefix[MAX];
  printf("Enter an infix expression: ");
  scanf("%s", infix);

  infixToPrefix(infix, prefix);
  printf("Prefix Expression: %s\n", prefix);

  return 0;
}