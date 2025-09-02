#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int calc(int v1, int v2, char op) {
    switch (op) {
        case '^': return pow(v1, v2);
        case '*': return v1 * v2;
        case '/': return v1 / v2;
        case '+': return v1 + v2;
        case '-': return v1 - v2;
        default: return 0;
    }
}

int eval(const string &s) {
    stack<int> st;
    for (char ch : s) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int v2 = st.top(); st.pop();
            int v1 = st.top(); st.pop();
            st.push(calc(v1, v2, ch));
        }
    }
    return st.top();
}

int main() {
    string s = "231*+9-";
    cout << "Result: " << eval(s) << endl;
    return 0;
}
