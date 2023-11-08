 /*
 * Author: Muhammad Xayrullayev
 * Date: 4/11/2023
 * Name: Muhammad Xayrullayev
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int calculatePostfixExpression(const string& postfix) {
    stack<int> operandStack;

    for (char token : postfix) {
        if (isdigit(token)) {
            // If it's a digit, convert it to an integer and push it onto the stack
            operandStack.push(token - '0');
        } else if (token == '+' || token == '-' || token == '*') {
            // If it's an operator, pop the top two operands from the stack
            if (operandStack.size() < 2) {
                cerr << "Invalid postfix expression" << endl;
                return 0;
            }
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            // Perform the operation and push the result back onto the stack
            int result;
            if (token == '+') {
                result = operand1 + operand2;
            } else if (token == '-') {
                result = operand1 - operand2;
            } else if (token == '*') {
                result = operand1 * operand2;
            }
            operandStack.push(result);
        }
    }

    if (operandStack.size() != 1) {
        cerr << "Invalid postfix expression" << endl;
        return 0;
    }

    return operandStack.top();
}

int task_3() {
    string postfixExpression;
    cin >> postfixExpression;

    int result = calculatePostfixExpression(postfixExpression);
    cout << result << endl;

    return 0;
}
