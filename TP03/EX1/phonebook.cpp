#include <iostream>
#include "contact.h"
using namespace std;
#include <string>



class phoneBook{

    contact contArr[8];
    int index=0; // represents the index of the first empty spot in the phonebook(0-8) with default value 0
    public:
    void ADD();
    void SEARCH();
    ~phoneBook(){
        cout<<"the phone book is deconstructed!" <<endl;// destructor for the exit method, it's automatically executed once out of the main function
    }
};


void phoneBook::ADD(){
    contact c;
    c.getdata();
    cout<<"Contact created!"<<endl<<endl;
    if(index==8){
        contArr[0]=c;
        return;
    }
    contArr[index]=c;
    index++;
    return;
    
}
void phoneBook::SEARCH(){
    for(int i=0; i<index;i++){
        cout<<i<<" | ";
        contArr[i].showdata();
    }
    return;
}

void contact:: getdata(){//Definition of function
    cout<<"First Name : ";
    cin>>first_name;
    cout<<"Last Name : ";
    cin>>last_name;
    cout<<"Nickname : ";
    cin>>nick_name;
    cout<<"Phone Number : ";
    cin>>phone_number;
}

void contact::showdata(){//Definition of function
    cout<<makeTen(first_name)<<" | ";
    cout<<makeTen(last_name)<<" | ";
    cout<<makeTen(nick_name)<<" ";
    cout<<endl;
}

int main(){
    string user_input;
    cout<<"Enter command :\n add: save a new contact\n search: display contacts\n exit: exit, WARNING: the contacts will be lost!"<<endl;
    phoneBook phonebook1; 
    while(1){ // we will keep the user in the phonebook until 'EXIT'
    cout<<">> ";
    cin >>user_input;
    if(user_input.compare("add")==0){
        phonebook1.ADD();
    }
    if(user_input.compare("search")==0){
        cout<<makeTen("First Name")<<" | ";
        cout<<makeTen("Last Name")<<" | ";
        cout<<makeTen("Nickname")<<" "<<endl;
        phonebook1.SEARCH();
    }
    // if(strcasecmp(user_input,"exit")=) case insensitive comparison (?)
    if(user_input.compare("exit")==0){
        return 0; // exit the main function and the destructor is called, the phonebook is lost
    }
    else{
        cout<<"Command Not Found!";
    }
    
    }
    

}
