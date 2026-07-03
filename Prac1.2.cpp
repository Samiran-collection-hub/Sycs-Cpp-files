#include <iostream>
using namespace std;
const int MAX = 100;

struct Student
{
    int id;
    char name[50];
    int age;
};

void newst(Student students[],int &count){
    if(count>=MAX){cout<<"maximum limit reached.\n";}
    cout<<"Enter ID: ";
    cin>>students[count].id;
    cout<<"Enter name: ";
    cin.getline(students[count].name,50);
    cout<<"Enter age: ";
    cin>>students[count].age;
    count++;
    cout<<"Student created successfully.\n";
}

void upst(Student students[],int count){
    int id;
    cout<<"Enter id to update: ";
    cin>>id;
    for(int i=0;i<count;i++){
        if(students[i].id==id){
            cout<<"Enter new name: ";
            cin.getline(students[i].name,50);
            cout<<"Enter new age: ";
            cin>>students[i].age;
            cout<<"Studen update successfully.\n";
        }
    }
    cout<<"Student not found.\n";
}

void delst(Student students[],int count){
    int id;
    cout<<"Enter id to delete: ";
    cin>>id;
    for(int i=0;i<count;i++){
        if(students[i].id==id){
            for(int j=i;j<count-1;j++){
                students[j]=students[j+1];
            }
            count--;
            cout<<"Student deleted.\n"; return;
        }
    }
    cout<<"Student not found.\n";
}

void dis(Student students[],int count){
    cout<<"\n---Student list---\n";
    for(int i=0;i<count;i++){
        cout<<"ID:"<<students[i].id<<"\nName:"<<students[i].name<<"\nAge :"<<students[i].age<<endl;
    }
    if(count==0){cout<<"No students to display.\n";}
}

int main() 
{
    Student students[MAX];
    int count=0;
    int choice;

    do{
        cout<<"\n1.Create Student\n2.Update Student\n3.Delete Student\n4.Display students\n5.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1: newst(students,count);break;
            case 2: upst(students,count);break;
            case 3: delst(students,count);break;
            case 4: dis(students,count);break;
            case 5: cout<<"Exiting..\n";break;
            default: cout<<"invalide";
        }
    }while(choice!=5);

    return 0;
}
