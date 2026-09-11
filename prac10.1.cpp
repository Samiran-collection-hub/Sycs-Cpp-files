#include <iostream>
using namespace std;

class HashTable{
    private:
    static const int SIZE=10;
    int table[SIZE];
    int hashFunction(int key){
        return key%SIZE;
    }
    public:
    HashTable(){
        for (int i = 0; i < SIZE; i++) table[i]=-1;
    }
    void insert(int key){
        int index=hashFunction(key);
        int startindex = index;
        while(table[index]!=-1){
            index = (index+1)%SIZE;
            if(index==startindex){
                cout<<"HashTable is full";
                return;
            }
        }
        table[index]=key;
    }
    bool search(int key){
        int index=hashFunction(key);
        int startindex = index;
        while(table[index]!=-1){
            index = (index+1)%SIZE;
            if(index==startindex) break;
        }
        return false;
    }
    void remove(int key){
        int index=hashFunction(key);
        int startindex = index;
        while(table[index]!=-1){
            if(table[index]==key){
                table[index]=-2; return;
            }
            index=(index+1)%SIZE;
            if(index==startindex) break;
        }
    }
    void dis(){
        for(int i=0;i<SIZE;i++) cout<<i<<": "<<table[i]<<endl;
    }
};
int main() 
{
    HashTable ht;
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.dis();
    cout<<"Search 15: "<<(ht.search(15)? "Found\n":"Not Found\n");
    ht.remove(15);
    cout<<"After removing 15:\n";
    ht.dis();
    return 0;
}
