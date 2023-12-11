#include <iostream>
#include <iomanip>

using namespace std;

void readArrayRecursively(double* arr, int n, int index = 0) {
    if (index == n) {
        return;
    }

    cout << setw(4) << "elem: " << index + 1 << ": ";
    cin >> arr[index];

    readArrayRecursively(arr, n, index + 1);
}

void prontArrayRecursively(double* arr, int n, int index = 0) {
    if (index == n) {
        cout << endl;
        return;
    }

    cout << setw(4) << arr[index] << " ";
    prontArrayRecursively(arr, n, index + 1);
}

double sumOfNegativeElementsRecursively(const double* arr, int n, int index = 0) {
    if (index == n) {
        return 0;
    }

    double sum = (arr[index] < 0) ? arr[index] : 0;
    return sum + sumOfNegativeElementsRecursively(arr, n, index + 1);
}

double productBetweenMinMaxRecursively(const double* arr, int n, int min_index, int max_index) {
    if (min_index + 1 == max_index) {
        return 1;
    }

    double product = arr[min_index + 1] * productBetweenMinMaxRecursively(arr, n, min_index + 1, max_index);
    return product;
}

void sortEvenElementsRecursively(double* arr, int n, int i = 0) {
    if (i >= n) {
        return;
    }

    for (int j = i + 2; j < n; j += 2) {
        if (arr[i] > arr[j]) {
            double temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    sortEvenElementsRecursively(arr, n, i + 2);
}

int main() {
    int n;
    cout << "length array: ";
    cin >> n;
    double* arr = new double[n];

    readArrayRecursively(arr, n);
    cout << "old array:" << endl;
    prontArrayRecursively(arr, n);
    sortEvenElementsRecursively(arr, n);

    cout << setw(4) << "Sum: " << sumOfNegativeElementsRecursively(arr, n) << endl;

    cout << setw(4) << "Dob: " << productBetweenMinMaxRecursively(arr, n, 0, n) << endl;

    cout << "New array:" << endl;
    prontArrayRecursively(arr, n);
    cout << endl;

    delete[] arr;

    return 0;
}