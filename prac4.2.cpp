#include <string>
#include <iostream>
using namespace std;

struct Song{
    string title;
    Song* next;
};

class Playlist{
    private:
    Song* head;
    public:
    Playlist(){
        head = nullptr;
    }
    void addSong(const string&title){
        Song* newSong =new Song{title,nullptr};
        if(!head){
            head = newSong;
        }else{
            Song* temp = head;
            while(temp->next) temp=temp->next;
            temp->next=newSong;
        }
        cout<<"Added \""<<title<<"\" to playlist.\n";
    }
    void removeSong(const string&title){
        if(!head){
            cout<<"Playlist is empty!\n"; return;
        }
        if(head->title==title){
            Song* toDelete = head;
            head = head->next;
            delete toDelete;
            cout<<"Removed \""<<title<<"\" from playlist.\n"; return;
        }
        Song* temp = head;
        while(temp->next && temp->next->title != title) temp=temp->next;
        if(!temp->next){cout<<"Song \""<<title<<"\" not found!\n"; return;}
        Song* toDelete = temp->next;
        temp->next=temp->next->next;
        delete toDelete;
        cout<<"Removed \""<<title<<"\" from playlist.\n";
    }
    void Displaylist(){
        if(!head){
            cout<<"Playlist is empty.\n"; return;
        }
        cout<<"Current playlist:\n";
        Song* temp = head;
        int index =1;
        while(temp){
            cout<<index++<<". "<<temp->title<<endl;
            temp=temp->next;
        }
    }
    void playSong(){
        Song* temp=head;
        while(temp){
            cout<<"Now playing: "<<temp->title<<endl;
            temp=temp->next;
        }
    }
    ~Playlist(){
        while(head){
            Song* next=head->next;
            delete head;;
            head=next;
        }
    }
};

int main() 
{
    Playlist mypl;
    mypl.addSong("Shape of You");
    mypl.addSong("Believer");
    mypl.addSong("Faded");

    mypl.Displaylist(); cout<<endl;
    mypl.playSong(); cout<<endl;
    mypl.removeSong("Believer");
    mypl.Displaylist(); cout<<endl;
    mypl.removeSong("Non-existent Song");

    return 0;
}
