#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int getWeight(char ch){
    switch(ch){
        case '/':
        case '*':return 2;
        case '+':
        case '-':return 1;
        default:return 0;
    }
}
void infix2postfix(char infix[], char postfix[], int size){
    stack<char> s;
    int weight,i=0,k=0;
    char ch;
    while(i < size) {
    ch = infix[i];

    // 1. If it's an operand, add it to output immediately
    if(isalnum(ch)) {
        postfix[k++] = ch;
    }
    // 2. If it's '(', push to stack
    else if(ch == '(') {
        s.push(ch);
    }
    // 3. If it's ')', pop until '('
    else if(ch == ')') {
        while(!s.empty() && s.top() != '(') {
            postfix[k++] = s.top();
            s.pop();
        }
        s.pop(); // Remove the '('
    }
        // 4. If it's an operator, handle precedence
    else {
        while(!s.empty() && getWeight(s.top()) >= getWeight(ch)) {
            postfix[k++] = s.top();
            s.pop();
        }
        s.push(ch);
    }
    i++;
}

    // 5. After the loop, pop remaining operators
    while(!s.empty()) {
        postfix[k++] = s.top();
        s.pop();
    }
    postfix[k] = '\0';
}

int main(){
    char infix[]="A*(B+C)/D";
    int size=strlen(infix);
    char postfix[size];
    infix2postfix(infix, postfix, size);
    cout<<"\n infix expression::"<<infix<<endl;
    cout<<"\n postfix expresseion::"<<postfix<<endl;
    return 0;
}
