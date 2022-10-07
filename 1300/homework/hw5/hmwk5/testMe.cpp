#include <iostream>
#include <cassert>

using namespace std;

int zeroesToFives(int arr[], int arr_size)
{
	int count = 0;
	//loops through input array
	for(int i = 0; i < arr_size; i++) 
	{ 
		if(arr[i] == 0) //if an element is zero, set it to five
		{ 
    			arr[i] = 5;
			count++;
		}
	}
	return count;
}

int main() {
    // Test 1
    int arr1[] = {0, 1, 2, 3, 4, 5};
    int arr_size1 = 6;
    for (int i = 0; i < arr_size1; i ++) {
        cout << arr1[i];
    }
    cout << endl;
    assert(zeroesToFives(arr1, arr_size1) == 1);
    for (int i = 0; i < arr_size1; i ++) {
        cout << arr1[i];
    }
    cout << endl;
    // Test 2
    int arr2[1] = {};
    int arr_size2 = 10;
    for (int i = 0; i < arr_size2; i ++) {
        cout << arr2[i];
    }
    cout << endl;
    assert(zeroesToFives(arr2, arr_size2) == 0);
    for (int i = 0; i < arr_size2; i ++) {
        cout << arr2[i];
    }
    cout << endl;
    // Test 3
    int arr3[] = {1, 2, 0, 6, 0};
    int arr_size3 = 4;
    for (int i = 0; i < arr_size3; i ++) {
        cout << arr3[i];
    }
    cout << endl;
    assert(zeroesToFives(arr3, arr_size3) == 1);
    for (int i = 0; i < arr_size3; i ++) {
        cout << arr3[i];
    }
    cout << endl;
    // Test 4
    int arr4[] = {0, 0, 0, 0, 0};
    int arr_size4 = 5;
    for (int i = 0; i < arr_size4; i ++) {
        cout << arr4[i];
    }
    cout << endl;
    assert(zeroesToFives(arr4, arr_size4) == 5);
    for (int i = 0; i < arr_size4; i ++) {
        cout << arr4[i];
    }
    cout << endl;
    // Test 5
    int arr5[3] = {};
    int arr_size5 = 3;
    for (int i = 0; i < arr_size5; i ++) {
        cout << arr5[i];
    }
    cout << endl;
    assert(zeroesToFives(arr5, arr_size5) == 3);
    for (int i = 0; i < arr_size5; i ++) {
        cout << arr5[i];
    }
    cout << endl;
    // Test 6
    int arr6[] = {5, 5, 6, 7, 8};
    int arr_size6 = 5;
    for (int i = 0; i < arr_size6; i ++) {
        cout << arr6[i];
    }
    cout << endl;
    assert(zeroesToFives(arr6, arr_size6) == 0);
    for (int i = 0; i < arr_size6; i ++) {
        cout << arr6[i];
    }
    cout << endl;
    // Test 7
    int arr7[] = {5, 0, 5, 0};
    int arr_size7 = 4;
    for (int i = 0; i < arr_size7; i ++) {
        cout << arr7[i];
    }
    cout << endl;
    assert(zeroesToFives(arr7, arr_size7) == 2);
    for (int i = 0; i < arr_size7; i ++) {
        cout << arr7[i];
    }
    cout << endl;
    // Test 8
    int arr8[] = {1, 2, 3, 4, 5};
    int arr_size8 = 5;
    for (int i = 0; i < arr_size8; i ++) {
        cout << arr8[i];
    }
    cout << endl;
    assert(zeroesToFives(arr8, arr_size8) == 0);
    for (int i = 0; i < arr_size8; i ++) {
        cout << arr8[i];
    }
    cout << endl;
    // Test 9
    int arr9[] = {12, 0, 55, 0, 69};
    int arr_size9 = 5;
    for (int i = 0; i < arr_size9; i ++) {
        cout << arr9[i];
    }
    cout << endl;
    assert(zeroesToFives(arr9, arr_size9) == 2);
    for (int i = 0; i < arr_size9; i ++) {
        cout << arr9[i];
    }
    cout << endl;
    // Test 10
    int arr10[] = {0, 0, 0, 0, 0, 0, 0};
    int arr_size10 = 7;
    for (int i = 0; i < arr_size10; i ++) {
        cout << arr10[i];
    }
    cout << endl;
    assert(zeroesToFives(arr10, arr_size10) == 7);
    for (int i = 0; i < arr_size10; i ++) {
        cout << arr10[i];
    }
    cout << endl;

    return 0;
}