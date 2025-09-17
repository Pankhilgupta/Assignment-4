#include <iostream>
using namespace std;
int q[1000];
int n=1000;
int f=-1;
int r=-1;
void enqueue(int x){
    if(f==(r+1)%n){
        cout<<"Overflow";
    }
    r=(r+1)%n;
    q[r]=x;
    if(f==-1){
        f=0;
    }
}
void dequeue(){
    if(f==r && r==-1){
        cout<<"Underflow";
    }
    int i=q[f];
    if(f==r){
        f=-1;r=-1;
    }
    else{
        f=(f+1)%n;
    }
}
void isEmpty(){
    if(f==r && r==-1){
        cout<<"Empty queue";
    }
    else{
        cout<<"Queue is not empty";
    }
}
void isFull(){
    if(f==(r+1)%n){
        cout<<"Queue is full";
    }
    else{
        cout<<"Queue is not full";
    }
}
void peek(){
    cout<<q[f];
}
void display() {
    if (f == -1) {
        cout << "Empty\n";
        return;
    }
    int i = f;
    while (true) {
        cout << q[i] << " ";
        if (i == r) break;   // reached rear
        i = (i + 1) % n;    // wrap-around
    }
    cout << "\n";
}int main() {
    int choice, val;
    do {
        cout << "\n---- Menu ----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                isFull();
                break;
            default:
                cout << "Invalid choice\n";
        }
    }while(choice<7);

    return 0;
}
