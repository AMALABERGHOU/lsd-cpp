#include <iostream>
using namespace std;

class shape {
    public:
    int height;
    int width;
    shape(){ // constructor
        height=0;
        width=0;
    }
};

class triangle : public shape{
    public:
    int area(){
        return height*width/2;
    }
};
class rectangle : public shape{
    public:
    int area(){
        return height*width;
    }
};

int main(){
    triangle T;
    // T.height=2;
    // T.width=4;
    cout <<T.area()<<endl;
    return 0;
}
