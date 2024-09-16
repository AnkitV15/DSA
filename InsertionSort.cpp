// Insertion Sort
// input - 0,2,8,-2,3,5
// output - -2 0 2 3 5 8  

// time complexity - O(n^2)
// space complexity - O(1)

#include <iostream>
using namespace std;

void swap(int* varA, int* varB){
    int temp = *varA;
    *varA = *varB;
    *varB = temp;
}

int* GetSortArray(int* array,int size){

    for( int i = 1; i < size; i++){

        int key = array[i]; //-2
        int j = i - 1; //8

        while (j >= 0 && key < array[j])
        {
            swap(array[j + 1], array[j]);
            j--;
        }
    }

    return array;
}

void PrintArray(int* array,int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout <<"\n";
}

int main(){
    int array[] = {0,2,8,-2,3,5};
    int size = sizeof(array)/sizeof(array[0]);
    
    int* sortedArray = GetSortArray(array,size);
    
    PrintArray(sortedArray,size);
    return 0;
}