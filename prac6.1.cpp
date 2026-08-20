#include <iostream>
using namespace std;

class Node{
    public:
    int coff,pow;
    Node* next;
    Node(int c, int p){
        coff=c;
        pow=p;
        next=nullptr;
    }
};
class Poly{
    private:
    Node* head;
    Node* tail;
    public:
    Poly(){
        head=tail=nullptr;
    }
    void create(int coff,int pow){
        Node* newNode=new Node(coff,pow);
        if(head==nullptr){
            head=tail=newNode;
        } else {
            tail->next=newNode;
            tail=newNode;
        }
    }
    static Poly add(Poly& p1,Poly& p2){
        Node* poly1=p1.head;
        Node* poly2=p2.head;
        Poly result;

        while(poly1 && poly2){
            if (poly1->pow > poly2->pow){
                result.create(poly1->coff,poly1->pow);
                poly1=poly1->next;
            }else if(poly1->pow < poly2->pow){
                result.create(poly2->coff,poly2->pow);
                poly2=poly2->next;
            }else{
                int sum=poly1->coff + poly2->coff;
                result.create(sum,poly2->pow);
                poly1=poly1->next;
                poly2=poly2->next;
            }
        }
        while(poly1){
            result.create(poly1->coff,poly1->pow);
            poly1=poly1->next;
        }
        while(poly2){
            result.create(poly2->coff,poly2->pow);
            poly2=poly2->next;
        }
        return result;
    }
    void show(){
        Node* temp=head;
        while(temp){
            cout<<temp->coff<<"x^"<<temp->pow;
            if(temp->next) cout<<"+";
            temp=temp->next;
        }
    }
};

int main() 
{
    Poly poly1,poly2;
    poly1.create(5,2);
    poly1.create(4,1);
    poly1.create(2,0);

    
    poly2.create(5,1);
    poly2.create(5,0);

    cout<<"1st Polynomial: ";
    poly1.show();
    
    cout<<"\n2nd Polynomial: ";
    poly2.show();

    Poly result=Poly::add(poly1,poly2);
    cout<<"\nAddition Polynomial";
    result.show();
    
    return 0;
}
