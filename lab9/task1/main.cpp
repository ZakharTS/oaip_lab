#include <iostream>

using namespace std;

void add(int*& arr, size_t &arrSize, int el, size_t pos);
void DoubleX(int*& arr, size_t &arrSize, int toDouble);
void display(int* arr, size_t arrSize);

int main() {
    for(short j = 0; j < 3; j++) {
        int *A;
        size_t n;
        int x;
        cout << "Array size: ";
        cin >> n;
        A = new int[n];
        cout << "Array: ";
        for (size_t i = 0; i < n; i++) cin >> A[i];
        cout << "To double: ";
        cin >> x;
        DoubleX(A, n, x);
        display(A, n);
        cout << endl;
    }
    return 0;
}

void add(int*& arr, size_t &arrSize, int el, size_t pos) {
    if (pos <= arrSize) {
        int* newArr = new int[++arrSize];
        for (size_t i = 0; i < pos; i++) newArr[i] = arr[i];
        newArr[pos] = el;
        for (size_t i = pos + 1; i < arrSize; i++) {
            newArr[i] = arr[i-1];
        }
        delete[] arr;
        arr = newArr;
    }
}

void DoubleX(int*& arr, size_t &arrSize, int toDouble) {
    for (size_t i = 0; i < arrSize; i++) {
        if (arr[i] == toDouble) add(arr, arrSize, toDouble, ++i);
    }
}

void display(int* arr, size_t arrSize) {
    cout << "Array size: " << arrSize << endl;
    for (size_t i = 0; i < arrSize; i++) cout << arr[i] << " ";
    cout << endl;
}
