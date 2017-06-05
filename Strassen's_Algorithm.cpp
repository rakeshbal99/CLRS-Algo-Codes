#include <iostream>
using namespace std;

int SQUARE_MATRIX_ADDITION(int A[][100],int B[][100],int C[][100],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
				C[i][j]=A[i][j]+B[i][j];
	}
}

int SQUARE_MATRIX_SUBTRACTION(int A[][100],int B[][100],int C[][100],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
				C[i][j]=A[i][j]-B[i][j];
	}
}

int SQUARE_MATRIX_MULTIPLY_RECURSIVE(int A[][100],int B[][100],int C[][100],int n){
	if(n==1)
		C[1][1]=A[1][1]*B[1][1];
	else{
		for (int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			}
		}
	}
}



int main(){

	return 0;
}