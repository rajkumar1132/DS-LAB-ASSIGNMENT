
//Roll no: 1024031132

#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);

        // rotate the queue to put new element at front
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl; 
    s.pop();
    cout << "Top after pop: " << s.top() << endl; 

    return 0;
}
