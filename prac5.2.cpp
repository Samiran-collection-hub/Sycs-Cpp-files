#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=nullptr;
    }
};
class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head=nullptr;
    }
    void insertH(int value){
        Node* newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }
    void insertT(int value){
        Node* newNode=new Node(value);
        if(!head){head=newNode; return;}
        Node* temp=head;
        while(temp->next) temp=temp->next;
        temp->next=newNode;
    }
    void insertP(int position,int value){
        if(position==0){insertH(value); return;}
        Node* newNode=new Node(value);
        Node* temp=head;
        for(int i=0;i<position-1&&temp;++i) temp=temp->next;
        if(!temp){
            cout<<"Position out of bounds.\n"; return;
        } 
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void delH(){
        if(!head){cout<<"List id empty.\n"; return;}
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    void delT(){
        if(!head){cout<<"List id empty.\n"; return;}
        if(!head->next){
            delete head;
            head=nullptr;
            return;
        }
        
        Node* temp=head;
        while(temp->next&&temp->next->next) temp=temp->next;
        delete temp->next;
        temp->next=nullptr;
    }
    void delP(int position){
        if(!head){cout<<"List id empty.\n"; return;}
        if(position==0){delH(); return;}
        Node* temp=head;
        for(int i=0;i<position-1&&temp;++i) temp=temp->next;
        if(!temp||!temp->next){
            cout<<"Position oout of bounds.\n"; return;
        }
        Node*toDel=temp->next;
        temp->next=temp->next->next;
        delete toDel;
    }
    void dis(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};

int main(){
    LinkedList l;
    l.insertH(10);
    l.insertT(20);
    l.insertT(30);
    l.insertP(1,15);
    l.insertP(2,35);
    cout<<"List after insertions:\n";
    l.dis();

    l.delH();
    l.delT();

    l.delP(2);
    cout<<"List after delete:\n";
    l.dis();
    return 0;
}
