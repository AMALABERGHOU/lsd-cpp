# include <iostream>
using namespace std;
#include <vector>

vector<vector<int> > multiplyMatrices(vector<vector<int>> A,vector<vector<int> > B) {
    int n=A[0].size(); 
    vector<vector<int>> result(n, vector<int> (n, 0));// initializing result as the matrix containing n*n zeroes
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         for (int k = 0; k < n; k++) {
            result[i][j] += A[i][k] * B[k][j];
         }
      }
  }
  return result;
}

void matprint(vector<vector<int> > A){
    int n=A[0].size();
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return ;
}


vector<vector<int> > matpowNaive(vector<vector<int> > M,int k){
    int n=M[0].size();
    vector<vector<int>> res(n, vector<int> (n, 0)); // initializing res as the matrix containing n*n zeroes
    // initializing res as the identity matrix
      for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
          if(i==j){
         res[i][j] = 1; 
          }
          else {
         res[i][j] = 0;}
      }
}
    for(int i=0; i<k;i++){
        
        res=multiplyMatrices(res,M);
        } 
    return res;
}

vector<vector<int> > matpow(vector<vector<int> > M , int k){
    int n=M[0].size();
    vector<vector<int>> res(n, vector<int> (n, 0)); // initializing res as the matrix containing n*n zeroes
    // initializing res as the identity matrix
      for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
          if(i==j){
         res[i][j] = 1; 
          }
          else {
         res[i][j] = 0;}
      }
}
vector<vector<int> > I=res;
    while(k!=0){
	    if(k%2==1){
	        res = multiplyMatrices(res,M);
	    }
	       M = multiplyMatrices(M,M);
	    k = k/2;
	    
	}
	return res;
    
}

int main(){
    vector<vector<int> > A ={{1,2,3},{2,0,0},{0,1,3}};
    vector<vector<int> > B ={{1,0,0},{0,1,0},{0,0,1}};
    vector<vector<int> > C=matpowNaive(A,3);
    printf("A^k using the naive method: \n");
    matprint(C);
    vector<vector<int> > D=matpow(A,3);
    printf("A^k using the iterative method: \n");
    matprint(D);
    
    
    
    return 0;
    
}
