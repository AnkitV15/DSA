//Circular Queue (again with pointers)
#include <iostream>
using namespace std;

#define SIZE 10

class CQueue{
    public:
    int front;
    int rear;
    int items[SIZE];
    CQueue(){
        front = -1;
        rear = -1;
    }
};

bool IsFull(CQueue *q){
    if(q->front == 0 && q->rear == SIZE - 1)
        return 1;
    if(q->front == q->rear + 1)
        return 1;
        
        return 0;
}

bool IsEmpty(CQueue *q){
    if(q->front == -1 && q->rear == -1)
        return 1;
    else 
        return 0;
}

void EnQueue(CQueue *q, int newItem){
    if(IsFull(q))
        cout<<"Queue is Full!"<<endl;
    else {
        if(q->front == -1 ) q->front = 0;
         q->rear = (q->rear + 1) % SIZE;
         q->items[q->rear] = newItem;
    }
}


void DeQueue(CQueue *q){
    if(IsEmpty(q))
        cout<<"Queue is Full!"<<endl;
    else {
        if(q->front == q->rear)
        {
            q->front  = -1;
            q->rear  = -1;
        }
        else
        {
             q->front = (q->front + 1) % SIZE;
        }
    }
    
}


void Print(CQueue *q){
    if(IsEmpty(q))
        cout<<"Queue is Empty!"<<endl;
    else {
        cout<<"Elements: ";
        for (int i = q->front ; i <= q->rear ; i = (i + 1) % SIZE){
            cout<<q->items[i]<<" ";
        }
    }
}




int main() {
    CQueue *q = new CQueue;
    
    cout<<"Welcome to Circular Queue!"<<endl;
    cout<<"Enter no of elements to Add : "<<endl;
    int noOfElementsToAdd;
    cin>>noOfElementsToAdd;
    
    cout<<"Enter Elements: ";
    while(noOfElementsToAdd--){
        int elements;
        cin>>elements;
        EnQueue(q,elements);
    }
    cout<<"Enter no of elements to Remove : "<<endl;
    int noOfElementsToRemove;
    cin>>noOfElementsToRemove;
    while(noOfElementsToRemove--){
        DeQueue(q);
    }
    
    Print(q);
    
    return 0;
}
