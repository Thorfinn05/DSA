#include <stdio.h>
#include <ctype.h> // for isalnum() and isdigit()
#include <stdlib.h> // for atoi()
#include <math.h> // for pow()

#define MAX 100

// Stack to hold operators
char stack[MAX];
int top = -1;

// Stack to hold operands for evaluation
int evalStack[MAX];
int evalTop = -1;

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

// Function to get precedence of operators
int precedence(char c) {
    if(c == '+' || c == '-') {
        return 1;
    } else if(c == '*' || c == '/' || c == '%') {
        return 2;
    } else if(c == '^') {
        return 3; // Exponentiation has higher precedence
    } else {
        return 0;
    }
}

// Function to check if the operator is right-associative (for exponentiation)
int isRightAssociative(char c) {
    return (c == '^');
}

// Function to push an operator to the stack
void push(char c) {
    if(top < MAX - 1) {
        stack[++top] = c;
    }
}

// Function to pop an operator from the stack
char pop() {
    if(top >= 0) {
        return stack[top--];
    }
    return -1; // Stack underflow
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c, temp;

    while((c = infix[i++]) != '\0') {
        // If the character is an operand (alphanumeric), add it to the output
        if(isalnum(c)) {
            postfix[j++] = c;
            postfix[j++] = ' '; // Add space between operands/operators
        }
        // If the character is '(', push it to the stack
        else if(c == '(') {
            push(c);
        }
        // If the character is ')', pop from the stack until '(' is found
        else if(c == ')') {
            while(top >= 0 && stack[top] != '(') {
                postfix[j++] = pop();
                postfix[j++] = ' '; // Add space between operands/operators
            }
            pop(); // Pop '('
        }
        // If the character is an operator
        else if(isOperator(c)) {
            // Handle the precedence and associativity of operators
            while(top >= 0 && (precedence(stack[top]) > precedence(c) || 
                (precedence(stack[top]) == precedence(c) && !isRightAssociative(c)))) {
                postfix[j++] = pop();
                postfix[j++] = ' '; // Add space between operands/operators
            }
            push(c);
        }
    }

    // Pop all remaining operators from the stack
    while(top >= 0) {
        postfix[j++] = pop();
        postfix[j++] = ' '; // Add space between operands/operators
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Function to push an operand to the evaluation stack
void evalPush(int value) {
    if(evalTop < MAX - 1) {
        evalStack[++evalTop] = value;
    }
}

// Function to pop an operand from the evaluation stack
int evalPop() {
    if(evalTop >= 0) {
        return evalStack[evalTop--];
    }
    return -1; // Stack underflow
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    int i = 0;
    char c;
    int operand1, operand2, result;

    while((c = postfix[i++]) != '\0') {
        // If the character is an operand (digit), push it to the stack
        if(isdigit(c)) {
            int num = 0;
            while(isdigit(c)) {
                num = num * 10 + (c - '0');
                c = postfix[i++];
            }
            i--; // Adjust for the extra increment
            evalPush(num);
        }
        // If the character is an operator, pop two operands and apply the operator
        else if(isOperator(c)) {
            operand2 = evalPop();
            operand1 = evalPop();
            switch(c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '%': result = operand1 % operand2; break;
                case '^': result = (int)pow(operand1, operand2); break;
            }
            evalPush(result);
        }
    }

    // The final result will be the only value left in the stack
    return evalPop();
}

int main() {
    char infix[MAX], postfix[MAX];
    
    // Input the infix expression
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    
    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    
    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);
    
    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    
    // Output the result of evaluation
    printf("Result of evaluation: %d\n", result);

    return 0;
}
