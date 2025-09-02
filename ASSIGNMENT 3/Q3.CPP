#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(const string &str) {
    stack<char> st;
    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else {
            if (ch == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            } else if (ch == ']' && !st.empty() && st.top() == '[') {
                st.pop();
            } else if (ch == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string str;
    cout << "Enter an expression with brackets: ";
    cin >> str;

    if (isValid(str)) {
        cout << "Brackets are balanced!" << endl;
    } else {
        cout << "Brackets are unbalanced!" << endl;
    }

    return 0;
}
