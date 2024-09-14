// Selection Sort
// input - 0,2,8,-2,3,5
// output - -2 0 2 3 5 8  

// time complexity - O(n^2)
// space complexity - O(1)

#include <iostream>
using namespace std;

void swap(int* varA, int* varB){
    int* temp = varA;
    varA = varB;
    varB = temp;
}

int* GetSortArray(int* array,int size){

    for( int i = 0; i < size - 1; i++){

        int minIndx = i;

        for(int j = i + 1; j < size; j++){
        
            if(array[j] < array[minIndx]){
                minIndx = j;
            }
        }
        if (minIndx != i) 
            swap(array[i], array[minIndx]);
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