#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> undoStack;
    string text="";
    int choice;
    string input;
    
    do{
        cout<<"Current text:\""<<text<<"\""<<endl;
        cout<<"1.Type\n2.Undo\n3.Exit\nChoose an option: ";
        cin>>choice;
        
        switch(choice){
            case 1:
            cout<<"Enter text to append: ";
            cin>>input;
            undoStack.push(text);
            text+=input;
            break;
            case 2:
            if(!undoStack.empty()){
                text=undoStack.top();
            }else{
                cout<<"Nothig to undo\n";
            }
            break;
            case 3:
            cout<<"Exiting...\n";
            break;
            default:
            cout<<"Invalid option.\n";
        }
    }while(choice!=3);
    return 0;
}
