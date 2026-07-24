#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        data=value;
        prev=nullptr;
        next=nullptr;
    }
};

class DoublyLinedList{
    private:
    Node* head;
    public:
    DoublyLinedList(){head=nullptr;}
    void append(int value){
        Node* newNode=new Node(value);
        if(head==nullptr){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr) temp=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
    }
    void disf(){
        Node* temp=head;
        cout<<"Forward: ";
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void disb(){
        if(head==nullptr){cout<<"List is empty.\n";return;}
        Node* temp=head;
        while(temp->next!=nullptr) temp=temp->next;
        cout<<"Backward: ";
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }
};

int main() 
{
    DoublyLinedList dll;

    dll.append(10);
    dll.append(20);
    dll.append(30);
    dll.append(40);

    dll.disf();
    dll.disb();
    return 0;
}
