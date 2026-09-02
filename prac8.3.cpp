#include <iostream>
using namespace std;

int heap[100];
int n=0;
void insert(int value){
    int i=n;
    heap[n]=value;
    n++;
    while(i>0){
        int parent=(i-1)/2;
        if(heap[parent]<=heap[i])
        break;
        swap(heap[parent],heap[i]);
        i=parent;
    }
}
void dis(){
    for(int i=0;i<n;i++) cout<< heap[i]<< " ";
}

int main() 
{
    insert(30);
    insert(10);
    insert(20);
    insert(5);
    insert(40);
    cout<< "min heap: ";
    dis();
    return 0;
}
