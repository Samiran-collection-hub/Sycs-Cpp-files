#include <list>
#include <iostream>
using namespace std;

class HashTable{
    private:
    static const int SIZE=5;
    list<int> table[SIZE];
    int hashFunction(int key){
        return key % SIZE;
    }
    public:
    void insert(int key){
        int index=hashFunction(key);
        table[index].push_back(key);
        cout<<"insert "<<key<<" at bucket "<<index<<endl;
    }
    bool sear(int key){
        int index=hashFunction(key);
        for(auto &x:table[index]){
            if(x==key){
                cout<<"Found "<<key<<" in bucket"<<index<<endl;
                return true;
            }
        }
        cout<<key<<"not found\n";
        return false;
    }
    void remove(int key){
        int index=hashFunction(key);
        table[index].remove(key);
        cout<<"Removed"<<key<<" from bucket"<<index<<endl;
    }
    void dis(){
        cout<<"\nHash table state:\n";
        for(int i=0;i<SIZE;i++){
            cout<<i<<": ";
            for(auto &x:table[i]){
                cout<<x<<"->";
            }
            cout<<"NULL\n";
        }
        cout<<endl;
    }
};

int main() 
{
    HashTable ht;
    ht.insert(10);
    ht.insert(15);
    ht.insert(7);
    ht.insert(12);
    ht.dis();
    ht.sear(15);
    ht.sear(5);
    ht.remove(15);
    ht.dis();
    return 0;
}
