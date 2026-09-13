#include <iostream>
using namespace std;

class Hashtable{
    private:
    static const int SIZE=5;
    int table[SIZE];
    int hashFunction(int key){
        return key%SIZE;
    }
    public:
    Hashtable(){
        for (int i = 0; i < SIZE; i++) table[i]=-1;
    }
    void insert(int key){
        int index=hashFunction(key);
        int startindex=index;
        while(table[index]!=-1&&table[index]!=-2){
            index=(index+1)%SIZE;
            if(index==startindex){
                cout<<"Hashtable is full\n"; return;
            }
        }
        table[index]=key;
        cout<<"insert "<<key <<"at index"<<index<<endl;
    }
    bool search(int key){
        int index=hashFunction(key);
        int startindex=index;
        while(table[index]!=-1){
            if(table[index]==key){
                cout<<"Founde "<<key <<"at index" <<index<<endl; return true;
            }
            index=(index+1)%SIZE;
            if(index==startindex) break;
        }
        cout<<key<<" not found\n";
        return false;
    }
    void remove(int key){
        int index=hashFunction(key);
        int startindex=index;
        while(table[index]!=-1){
            if(table[index]==key){
                table[index]=-2;
                std::cout << "removed" <<key <<"from index" << index << std::endl;
                return;
            }
            index=(index+1)%SIZE;
            if(index==startindex) break;
        }
        cout<<key<<"not found!\n";
    }
    void dis(){
        cout<<"\nhash tabel state:\n";
        for(int i=0;i<SIZE;i++){
            cout<<i<<": "<<table[i]<<endl;
        }
        std::cout  << std::endl;
    }
};
int main() 
{
    Hashtable ht;
    ht.insert(10);
    ht.insert(15);
    ht.insert(7);
    ht.insert(12);
    ht.dis();
    ht.search(15);
    ht.search(5);
    ht.remove(15);
    ht.dis();
    return 0;
}
