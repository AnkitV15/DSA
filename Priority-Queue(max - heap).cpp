#include<bits/stdc++.h>

using namespace std;

void Swap( int *a ,int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void Heapify(vector<int> &arr , int index){
    int largest = index;
    int leftChild =  2 * index + 1;
    int rightChild =  2 * index + 2;
    
    int size = arr.size();
    
    if(leftChild < size && arr[leftChild] > arr[index])
        largest = leftChild;
    if(rightChild < size && arr[rightChild] > arr[index])
        largest = rightChild;
    
   if(largest != index){
       Swap(&arr[index],&arr[largest]);
       Heapify(arr,largest);
   }
}

void Insert(vector<int> &arr,int newItem){
    if(arr.size() == 0)
       arr.push_back(newItem); 
     else {
       arr.push_back(newItem); 
       for(int i = arr.size() / 2 - 1 ; i >= 0 ; i--){
           Heapify(arr,i);
       }
    }
}

void Delete(vector<int> &arr,int itemtobeDeleted){
    int i;
    for(i = 0 ; i < arr.size(); i++){
        if(arr[i] == itemtobeDeleted)
            break;
    }
    Swap(&arr[i],&arr[arr.size() - 1]);
    arr.pop_back();
    
    for(int i = arr.size() / 2; i >= 0 ; i--){
        Heapify(arr,i);
    }
}

void printArray(vector<int> &arr){
    for(int i = 0 ; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr;
    Insert(arr,3);
    Insert(arr,4);
    Insert(arr,5);
    Insert(arr,6);
    Insert(arr,7);
    
    Delete(arr,6);
    
    printArray(arr);
    
    return 0;
}
