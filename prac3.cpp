#include <iostream>
#define SIZE 5
using namespace std;

class Queue{
    int items[SIZE],front,rear;
    public:
    Queue(){
        front = -1;
        rear = -1;
    }
    bool isfull(){return (front==0&&rear==SIZE-1) or (front==(rear+1)%SIZE);}
    bool ismt(){return front==-1;}
    void enQueue(int element){
        if(isfull()){
            cout<<"Queue is full";
        }else{
            if(front==-1) front=0;
            rear=(rear+1)%SIZE;
            items[rear]=element;
            cout<<"\ninserted "<<element<<endl;
        }
    }
    int deQueue(){
        int element;
        if(ismt()){
            cout<<"Queue is empty\n";
            return -1;
        }else{
            element = items[front];
            if(front==rear){front = -1; rear=-1;}else{front=(front+1)%SIZE;}
            return (element);
        }
    }
    void dis() {
        if (ismt()) {
            cout << "\nEmpty Queue\n";
        } else {
            cout << "Front -> " << front << endl;
            cout << "Items -> ";

            int i = front;
            while (true) {
                cout << items[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % SIZE;
            }

            cout << "\nRear -> " << rear << endl;
        }
    }
};

int main() {
    Queue q;
    q.deQueue();

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);

    q.dis();

    int elem=q.deQueue();

    if(elem!=-1)    cout<<"Deleted element is "<<elem<<endl;
    q.dis();
    q.enQueue(7);
    q.dis();
    q.enQueue(8);
    return 0;
}
