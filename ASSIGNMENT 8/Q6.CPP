//ASSIGNMENT 8 QUESTION 6
//ROLL NO.: 1024031132

#include <iostream>
using namespace std;

class PriorityQueue {
    int heap[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void push(int value) {
        heap[size] = value;
        int i = size;
        size++;

        while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int top() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    void pop() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        heap[0] = heap[size - 1];  // move last to root
        size--;

        heapifyDown(0);
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    bool empty() {
        return size == 0;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(40);
    pq.push(20);

    cout << "Priority Queue (Heap): ";
    pq.print();

    cout << "Max element (top): " << pq.top() << endl;

    pq.pop();
    cout << "After deleting max: ";
    pq.print();

    pq.pop();
    cout << "After deleting max again: ";
    pq.print();

    return 0;
}