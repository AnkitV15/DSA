//Queue using pointers (First In First Out)
// also stupid code
#include <iostream>
using namespace std;
#define MAX 10

class Queue {
    public :
    int front,rear;
    int items[MAX];
    Queue(){
        front = -1;
        rear = -1;
    }
};

bool IsFull(Queue *s){
    if(s->rear == MAX - 1 && s->front == 0)
        return 1;
    else 
        return 0;
}

bool IsEmpty(Queue *s){
    if(s->front == -1 && s->rear == -1)
        return 1;
    else 
        return 0;
}

void EnQueue(Queue *s, int newItem){
    if(IsFull(s))
        cout<<"Stack is Full!"<<endl;
    else {
        if(s->front == -1) s->front = 0;
        s->rear++;
        s->items[s->rear] = newItem;
    }
}

void DeQueue(Queue *s){
    if(IsEmpty(s))
        cout<<"Stack is Empty!"<<endl;
    else {
        if(s->front >= s->rear){
            s->front = -1;
            s->rear = -1;
        } else 
        s->front++;
    }
}

void Print(Queue *s){
    cout<<"Elements : ";
    for( int i = s->front; i <= s->rear; i++){
        cout<<s->items[i]<<" ";
    }
}

int main() {
    //Stack
    Queue *s = new Queue;
    int noOfElements,removeElements;
    cout<<"Enter no of elements to Enter: ";
    cin>>noOfElements;
    cout<<"Enter elements : ";
    while(noOfElements--){
        int input;
        cin>>input;
        EnQueue(s,input);
    }
    
    cout<<"Enter no of elements to Remove: ";
    cin>>removeElements;
    
    while(removeElements--){
        DeQueue(s);
    }
    
    Print(s);
    
    
    return 0;
}
