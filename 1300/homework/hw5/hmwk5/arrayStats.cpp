// arrayStats.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 5 - Problem 2 

#include <iostream>
#include <iomanip>

using namespace std;

double min(double arr[], int arr_size) {

    double min = arr[0];

    for (int i = 1; i < arr_size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

double sum(double arr[], int arr_size) {

    double sum = 0;

    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];
    }

    return sum;
}

double average(double arr[], int arr_size) {

    double average = sum(arr, arr_size) / double(arr_size);

    return average;
}

int main(){

    double arr[] = {1.24, 5.68, 3.456};
    int arr_size = 3;
    cout << "Min: " << fixed << setprecision(3)<< min(arr, arr_size) << endl;
    cout << "Sum: " << fixed << setprecision(3) << sum(arr, arr_size) << endl;
    cout << "Avg: " << fixed << setprecision(3) << average(arr, arr_size) << endl;


    return 0;
}