# include <iostream>
using namespace std;

//ex2
int powiter(int a, int k){ // calculating a**k iterative version
    int res=1;
    while(k!=0){
	    if(k%2==1){
	        res = res*a;
	    }
	       a = a*a;
	    k = k/2;
	    
	}
	return res;
    
}
int powrec(int a , int k){// calculating a**k recursive version
    if(k==0){
        return 1;
    }
    else if(k%2==1){
        return a*powrec(a,(k-1)/2)*powrec(a,(k-1)/2);
    }
    else{
        return powrec(a,k/2)*powrec(a,k/2);
    }
}



int main(){
    cout <<"iterative result: "<< powiter(3,3);
    cout <<"\nrecursive result: "<< powrec(3,3);
    
    return 0;
}
