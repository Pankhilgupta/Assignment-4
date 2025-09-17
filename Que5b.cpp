#include <iostream>
using namespace std;

const int MAX = 1000;
int q[1000];
int front = 0, rear = 0; //initially kept 0 

void enqueue(int x) {
  if (rear==MAX-1) {
    cout << "Queue is full\n"; 
    return -1; 
  }
    q[rear]=x;
    rear++;
}

int dequeue() {
    if (front == rear || front>rear) {
        cout << "Queue is empty\n";
        return -1;
    }
    return q[front++];
}

bool isEmpty() {
    return front == rear || front>rear;
}

void push(int x) {
    enqueue(x);
    int size = rear - front;
    for (int i = 0; i < size - 1; ++i) {
        int val = dequeue();
        enqueue(val);
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return dequeue();
}

int top() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return q[front];
}

bool empty() {
    return isEmpty();
}

int main() {
    push(10);
    push(20);
    cout << top() << endl; // 20
    cout << pop() << endl; // 20
    cout << pop() << endl; // 10
    cout << empty() << endl; // 1 (true)

    return 0;
}
