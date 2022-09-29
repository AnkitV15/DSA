//Hashtable 

#include<bits/stdc++.h>

using namespace std;

class HashTable{
    public:
    int capacity;
    list<int> *table;
    
    public : 
    HashTable(int v);
    int checkPrime(int n)
  {
  int i;
  if (n == 1 || n == 0)
  {
    return 0;
  }
  for (i = 2; i < n / 2; i++)
  {
    if (n % i == 0)
    {
    return 0;
    }
  }
  return 1;
  }
  int getPrime(int n)
  {
  if (n % 2 == 0)
  {
    n++;
  }
  while (!checkPrime(n))
  {
    n += 2;
  }
  return n;
  }
  
  int hashFunction(int key){
    return (key % capacity);
}
    
};

HashTable::HashTable( int v){
    int size = getPrime(v);
  this->capacity = size;
  table = new list<int>[capacity];
}


void InsertItem(HashTable* h, int key,int data){
    int index = h->hashFunction(key);
    h->table[index].push_back(data);
}

void DeleteItem(HashTable* h, int key){
    int index = h->hashFunction(key);
    
    list<int>:: iterator i;
    for(i = h->table[index].begin(); i != h->table[index].end(); i++){
        
        if(*i == key)
            break;
    }
    
    if(i != h->table[index].end())
        
    h->table[index].erase(i);
}


void Display(HashTable *h){
    for (int i = 0; i < h->capacity; i++)
  {
  cout << "table[" << i << "]";
  for (auto x : h->table[i])
    cout << " --> " << x;
  cout << endl;
  }
}

int main()
{
    
    int key[] = {231, 321, 212, 321, 433, 262};
  int data[] = {123, 432, 523, 43, 423, 111};
  int size = sizeof(key) / sizeof(key[0]);

  HashTable h(size);

  for (int i = 0; i < size; i++)
  InsertItem(&h,key[i], data[i]);

  DeleteItem(&h,12);
  Display(&h);
    return 0;
}
