# include <iostream>
using namespace std;

//ex 1
template <typename T> T multiply(T a, T b)
{
    return a*b;
}
int main()
{
    cout << multiply<float> (3,2)<< endl;
    cout << multiply<float> (1.2,2)<< endl;
    return 0;
    
}
