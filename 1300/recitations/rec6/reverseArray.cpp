#include <iostream>
#include <cassert>

using namespace std;

void swap(int my_array[], int start_index, int end_index) {
    int temp_storage = my_array[start_index];
    my_array[start_index] = my_array[end_index];
    my_array[end_index] = temp_storage;
}

void reverseArray(int my_array[], int my_array_length) {
    int swap_amount = my_array_length / 2;
    for (int i = 0; i < swap_amount; i++) {
        swap(my_array, i, my_array_length - 1 - i);
    }
}

int main(){
    
    int my_array_length;

    cout << "Please enter the size of your array:" << endl;
    cin >> my_array_length;
    int my_array[my_array_length];
    cout << "Please enter all the elements of your array:" << endl;
    for (int i = 0; i < my_array_length; i++) {
        cin >> my_array[i];
    }
    cout << "The reversed array is:" << endl;
    reverseArray(my_array, my_array_length);
    for (int i = 0; i < my_array_length; i++) {
        cout << my_array[i] << " ";
    }
    cout << endl;
    

    int test_array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int copy_test_array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverseArray(test_array1, 10);
    for (int i = 0; i < 10; i++) {
        assert(test_array1[i] == copy_test_array1[9-i]);
    }
    int test_array2[5] = {2, 4, 6, 8, 10};
    int copy_test_array2[5] = {2, 4, 6, 8, 10};
    reverseArray(test_array2, 5);
    for (int i = 0; i < 5; i++) {
        assert(test_array2[i] == copy_test_array2[4-i]);
    }
    int test_array3[7] = {1, 2, 3, 2, 1, 2, 3};
    int copy_test_array3[7] = {1, 2, 3, 2, 1, 2, 3};
    reverseArray(test_array3, 7);
    for (int i = 0; i < 7; i++) {
        assert(test_array3[i] == copy_test_array3[6-i]);
    }

    return 0;
}