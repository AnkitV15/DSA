// Some Stupid Code by ankit
#include <iostream>
using namespace std;
#define  MAX 10
int size = 0;

class Stack{
    public:
  int top;
  int item[MAX];
};

bool isEmpty(Stack *s){
    if(s->top == -1)
        return 1;
    else 
        return 0;
}

bool isFull(Stack *s){
    if(s->top == MAX - 1)
        return 1;
    else 
        return 0;
}

void CreateEmptyStack(Stack *s){
    s->top = -1;
}

void Push(Stack *s , int newItem){
    if(isFull(s))
        cout<<"Stack is Full!"<<endl;
    else {
        s->top++;
        s->item[s->top] = newItem;
    }
    size++;
}


void Pop(Stack *s){
    if(isEmpty(s))
        cout<<"Stack is Empty!"<<endl;
    else {
        s->top--;
    }
    size--;
}
void Print(Stack *s){
    cout<<"The Elements in the Stack are: ";
    for (int i = 0 ; i < size; i++){
        cout<<s->item[i]<<" ";
    }
    cout<<endl;
}

int main() {
    Stack *s = new Stack;
    CreateEmptyStack(s);
    cout<<"Enter memory size: ";
    int temp;
    cin>>temp;
    
    cout<<"Enter Elements to Add: "<<endl;
    
    while(temp--){
        int pushValue;
        cin>>pushValue;
        Push(s,pushValue);
    }
    
    Print(s);
    
    cout<<"Enter no of Elements to Remove: ";
    int removeValue;
    cin>>removeValue;
    
    while(removeValue--){
        Pop(s);
    }
    
    Print(s);
    
    return 0;
}
