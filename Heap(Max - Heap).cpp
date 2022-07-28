#include<bits/stdc++.h>
using namespace std;

//function to swap two elements
void Swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

// function to heapify(max - heap) or arrange elements in descending order
// takes array and index to start from 
void Heapify(vector<int> &hp, int i ){
    int size = hp.size(); // reference to vector size
    int largest = i; // first index of non - leaf node [(2 / size) - 1]
    int leftChild  = 2 * i + 1; // get index of left child
    int rightChild  = 2 * i + 2; // get index of right child

    if(leftChild < size && hp[leftChild] > hp[largest] )
        largest = leftChild;

    if(rightChild < size && hp[rightChild] > hp[largest] )
        largest = rightChild;
    
    //recurse until current element is largest
    if(largest != i){
        Swap(&hp[i],&hp[largest]); // swap
        Heapify(hp,largest); // arrange in descending order
    }
}

// function to insert element in heap
void Insert(vector<int> &hp,int newItem){
    int size = hp.size();
    if(size == 0 )
        hp.push_back(newItem); // if heap is empty then add element
    else {
        hp.push_back(newItem);  // else add element 

        // and arrange in order or heapify(max - heap)
        for(int i = size /  2  - 1; i >= 0; i--){
            Heapify(hp, i);
        }
    }
}
//function to delete element in heap
void Delete(vector<int> &hp, int deleteItem){
    int size = hp.size();
    int i;
    for(i = 0; i < size ; i++){
        if(hp[i] == deleteItem)
        break;
    }
    Swap(&hp[i],&hp[size - 1]);

    hp.pop_back();

    for(int i = size / 2 - 1; i >= 0 ; i-- ){
        Heapify(hp,i);
    }
}

// print function to print heapified elements
void Print(vector<int> &hp){
    cout<<"Elements: ";
    for(int i = 0; i < hp.size(); i++ ){
        cout<<hp[i]<<" ";
    }

    cout<<endl;
}

int main(){

    vector<int> arr;

    Insert(arr, 3);
    Insert(arr, 4);
    Insert(arr, 9);
    Insert(arr, 5);
    Insert(arr, 2);

    Print(arr);


    Delete(arr,9);
    Print(arr);
    return 0;
}
