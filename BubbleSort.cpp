#include <iostream>

// input - 1,2,4,3,8,5
// output - 1,2,3,4,5,8 

// time complexity - O(n^2)
// space complexity -
using namespace std;

int* GetSortArray(int* array,int size){

    for( int i = 0; i < size - 1; i++){

        bool swapped = false;

        for(int j = 0; j < size - i - 1; j++){
        
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
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
    int array[] = {1,2,8,3,5};
    int size = sizeof(array)/sizeof(array[0]);
    
    int* sortedArray = GetSortArray(array,size);
    
    PrintArray(sortedArray,size);
    return 0;
}