#include <iostream>
using namespace std;
int SIZE=100;
char q[100];
int front = 0, rear = -1;

void enqueue(char c) {
    if(rear==SIZE-1){
        cout<<"Overflow";
    }
    rear++;
    q[rear] = c;
    if(front==-1){
        front =0;
    }
}
void dequeue() {
    if (front <= rear) {
        front++;
    }
    else{
        cout<<"Underflow";
    }
}
bool isEmpty() {
    return (front > rear||front==-1);
}

int main() {
    char input[] = {'a', 'a', 'b', 'c'};
    int n = 4;

    int freq[300] = {0};   

    for (int i = 0; i < n; i++) {
        char ch = input[i];
        freq[(int)ch]++;
        enqueue(ch);

        while (!isEmpty() && freq[(int)q[front]] > 1) {
            dequeue();
        }
        if (isEmpty()) {
            cout << "-1";
        } else {
            cout << q[front] << " ";
        }
    }

    cout << endl;
    return 0;
}
