#include <iostream>
using namespace std;

const int MAX = 1000;
int q1[1000], q2[1000];
int front1 = 0, rear1 = 0;
int front2 = 0, rear2 = 0;

void enqueue(int q[], int &rear, int x) {
   if (rear==MAX-1) {
        cout << "Queue is full\n";
        return -1;
    }
    q[rear++] = x;
}

int dequeue(int q[], int &front) {
    if (front == rear) {
        cout << "Queue is empty\n";
        return -1;
    }
    return q[front++];
}

bool isEmpty(int front, int rear) {
    return front == rear || front >rear;
}
void swap(int a[], int b[]) {
    for (int i = 0; i < MAX; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
void swapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void push(int x) {

    enqueue(q2, rear2, x);
    while (!isEmpty(front1, rear1)) {
        int val = dequeue(q1, front1);
        enqueue(q2, rear2, val);
    }
    swap(q1, q2);
    swap(front1, front2);
    swap(rear1, rear2);
}


int pop() {
    if (isEmpty(front1, rear1)) {
        cout << "Stack is empty\n";
        return -1;
    }
    return dequeue(q1, front1);
}

int top() {
    if (isEmpty(front1, rear1)) {
        cout << "Stack is empty\n";
        return -1;
    }
    return q1[front1];
}

bool empty() {
    return isEmpty(front1, rear1);
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
