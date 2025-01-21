#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h> // For power function
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1; // Indicating an error
    }
    return stack[top--];
}

int evaluatePostfix(char* postfix) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        // If the symbol is a digit
        if (isdigit(symbol)) {
            push(symbol - '0'); // Convert char digit to integer
        } 
        // If the symbol is an operator
        else {
            int op2 = pop(); // Pop the second operand
            int op1 = pop(); // Pop the first operand
            int result;

            switch (symbol) {
                case '+': 
                    result = op1 + op2; 
                    break;
                case '-': 
                    result = op1 - op2; 
                    break;
                case '*': 
                    result = op1 * op2; 
                    break;
                case '/': 
                    if (op2 != 0) {
                        result = op1 / op2;
                    } else {
                        printf("Division by zero error!\n");
                        return -1;
                    }
                    break;
                case '%': 
                    result = op1 % op2; 
                    break;
                case '^': 
                    result = pow(op1, op2); 
                    break;
                default: 
                    printf("Invalid operator: %c\n", symbol); 
                    return -1;
            }
            push(result); // Push the result back onto the stack
        }
    }

    return pop(); // The final result will be at the top of the stack
}

int main() {
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    if (result != -1) {
        printf("The result of the evaluation of the postfix expression: %d\n", result);
    }

    return 0;
}
