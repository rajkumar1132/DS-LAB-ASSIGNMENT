#include <iostream>
using namespace std;

#define MAX 100 
class Stack {
    char arr[MAX];
    int top;

public:
    Stack() : top(-1) {} 

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char ch) {
        if (isFull()) {
            cout << "Stack overflow! Unable to push " << ch << endl;
        } 
        else {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Unable to pop" << endl;
            return '\0';
        } 
        else {
            return arr[top--];
        }
    }
};

string reverseStringUsingStack(const string &str) {
    Stack stack;
    for (char ch : str) {
        stack.push(ch);
    }
    string reversedStr;
    while (!stack.isEmpty()) {
        reversedStr += stack.pop();
    }
    return reversedStr;
}

int main() {
    string input = "DataStructure";
    string reversed = reverseStringUsingStack(input);

    cout << "Original String: " << input << endl;
    cout << "Reversed String: " << reversed << endl;

    return 0;
}
