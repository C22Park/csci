/*
Charles Park
Section 5
3/9/23
Assignment 8	
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void generate(double arr[], int size, double lower, double upper) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = fmod(rand(), upper - lower + 1) + lower - .5;
        if (arr[i] < lower) {
            arr[i] += .5;
        }
    }
}

void print(double arr[], int size) {
    bool new_line = false;
    for (int i = 0; i < size; i++) {
        new_line = false;
        cout << arr[i] << " ";
        if (i % 10 == 9) {
            cout << "\n";
            new_line = true;
        }
    }
    if (!new_line) {
        cout << "\n";
    }
}

double average(double arr[], int size) {
    double average = 0;
    for (int i = 0; i < size; i++) {
        average += arr[i];
    }
    return average / size;
}

double min(double arr[], int size) {
    double min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double max(double arr[], int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void addX(double arr[], int size, double add) {
    for (int i = 0; i < size; i++) {
        arr[i] += add;
    }
}

int numLess(double arr[], int size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < average(arr, size)) {
            counter++;
        }
    }
    return counter;
}
int numLess(double arr[], int size, double limit) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < limit) {
            counter++;
        }
    }
    return counter;
}

int numMore(double arr[], int size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > average(arr, size)) {
            counter++;
        }
    }
    return counter;
}
int numMore(double arr[], int size, double limit) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > limit) {
            counter++;
        }
    }
    return counter;
}

double range(double arr[], int size) {
    double max = arr[0];
    double min = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return max - min;
}

int main() {
    double arr[100];
    generate(arr, 100, 1.1, 10.6);
    print(arr, 100);
    cout << "Average: " << average(arr, 100) << "\n"
         << "Min: " << min(arr, 100) << "\n"
         << "Max: " << max(arr, 100) << "\n"
         << "Less Than Average: " << numLess(arr, 100) << "\n"
         << "Less Than 5: " << numLess(arr, 100, 5) << "\n"
         << "More Than Average: " << numMore(arr, 100) << "\n"
         << "More Than 5: " << numMore(arr, 100, 5) << "\n"
         << "Range: " << range(arr, 100) << "\n";
    addX(arr, 100, 5);
    print(arr, 100);
    cout << "Average: " << average(arr, 100) << "\n"
         << "Min: " << min(arr, 100) << "\n"
         << "Max: " << max(arr, 100) << "\n"
         << "Less Than Average: " << numLess(arr, 100) << "\n"
         << "Less Than 5: " << numLess(arr, 100, 5) << "\n"
         << "More Than Average: " << numMore(arr, 100) << "\n"
         << "More Than 5: " << numMore(arr, 100, 5) << "\n"
         << "Range: " << range(arr, 100) << "\n";
}