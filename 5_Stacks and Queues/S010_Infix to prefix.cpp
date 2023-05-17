#include <bits/stdc++.h>
using namespace std;

// How to convert infix expression to prefix expression?

// To convert an infix expression to a prefix expression, we can use the stack data structure. The idea is as follows:

// Step 1: Reverse the infix expression. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
// Step 2: Convert the reversed infix expression to “nearly” postfix expression.
// While converting to postfix expression, instead of using pop operation to pop operators with greater than or equal precedence, here we will only pop the operators from stack that have greater precedence.
// Step 3: Reverse the postfix expression.
// The stack is used to convert infix expression to postfix form.

string infixToPostfix(string infix){

    // same infix to postfix code

    // While converting to postfix expression, instead of using pop operation to pop operators with greater than or equal precedence, here we will only pop the operators from stack that have greater precedence.
}

string infixToPrefix(string infix){

    int l = infix.size();
 
    // Reverse infix
    reverse(infix.begin(), infix.end());
 
    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
 
    string prefix = infixToPostfix(infix);
 
    // Reverse postfix
    reverse(prefix.begin(), prefix.end());
 
    return prefix;

}

   