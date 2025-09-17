#include <iostream>
using namespace std;

void interleave(int arr[], int n) {
    int half = n / 2;
    int result[100], k = 0;

    for (int i = 0; i < half; i++) {
        result[k++] = arr[i];       // from first half
        result[k++] = arr[i + half]; // from second half
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
        cout << endl;
}

int main() {
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = 6;
    interleave(arr, n);
    return 0;
}
