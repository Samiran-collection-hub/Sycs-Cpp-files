#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: " ;
    cin >> age;
    cout << "Hello, " << name << "! " << "Age, " << age;
    return 0;
}
