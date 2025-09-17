#include <iostream>
using namespace std;

int q[100], n = 100, f = -1, r = -1;

void enqueue(int x) {
    if (r == n - 1) {
        cout << "Queue is full" << endl;
    } else {
        if (f == -1) {
            f++;
        }
        r++;
        q[r] = x;
    }
}

void dequeue() {
    if (f == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << q[f] << endl;
        f++;
    }
}

void display() {
    if (f == -1) {
        cout << "Queue is empty" << endl;
    } else {
        for (int i = f; i <= r; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
}

void isEmpty() {
    if (f == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }
}

void isFull() {
    if (r == n - 1) {
        cout << "Queue is full" << endl;
    } else {
        cout << "Queue is not full" << endl;
    }
}

void peek() {
    if (f == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << q[f] << endl;
    }
}

int main() {
    int x, y;
    do {
        cout << "Enter your choice: ";
        cin >> x;
        switch (x) {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> y;
                enqueue(y);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                isFull();
                break;
            case 6:
                peek();
                break;
        }
    } while (x < 7);

    return 0;
}
