#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Linkedlist{
    private:
    Node* head;
    public:
    Linkedlist(){
        head = nullptr;
    }

    void insertAtEnd(int value){
        Node* newNode = new Node{value,nullptr};
        if(head==nullptr){
            head=newNode;
        }else{
            Node* temp = head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    void insertAtBeg(int value){
        Node* newNode = new Node{value,head};
        head = newNode;
    }

    void deleteNode(int value){
        if(head==nullptr){
            cout<<"List is mt\n";
            return;
        }
        if(head->data==value){
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout<<"Delte :"<<value<<endl;
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr && temp->next->data!=value){
            temp=temp->next;
        }

        if(temp->next==nullptr){
            cout<<"value not found";
            return;
        }

        Node* toDelete = temp->next;
        temp->next=temp->next->next;
        delete toDelete;
        cout<<"Delete :"<<value<<endl;
    }
    void dis(){
        if(head==nullptr){
            cout<<"List is empty\n"; 
            return;
        }
        Node* temp = head;
        cout<<"list: ";
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"Null\n";
    }
    ~Linkedlist(){
        Node* current= head;
        while(current!=nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() 
{
    Linkedlist list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(5);
    list.dis();

    list.deleteNode(20);
    list.dis();
    list.deleteNode(100);
    return 0;
}
