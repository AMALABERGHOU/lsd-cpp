#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>
using namespace std;

string makeTen(string a){
    int n=a.length();
    string res="";
    if(n==10){
    }
    if(n>10){
        res=a.substr(0,10);
    }
    if(n<10){
        res=a;
        for (int i=n; i<10;i++){
            res+=" ";}
            
    }
    return res;
}
class contact{
    string first_name;
    string last_name;
    string nick_name;
    string phone_number;
public:
    void getdata();//getting the data of the contact from the user
    void showdata();//showing the data of the contact

};

#endif
