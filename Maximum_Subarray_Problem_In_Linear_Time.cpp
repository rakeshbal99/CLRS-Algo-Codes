#include <iostream>
using namespace std;

typedef struct{
	int low;
	int high;
	int sum;
}msa;

msa FIND_MAXIMUM_SUBARRAY(int A[],int low,int high){
	int i;
	msa index_j,end_index_j;
	index_j.low=low;
	index_j.high=high;
	index_j.sum=A[low];
	end_index_j=index_j;
	for(i=1;i<high;i++){
		end_index_j.high=i;
		if(A[i]<0)
			end_index_j.sum+=A[i];
		else if(end_index_j.sum<0){
			end_index_j.sum=A[i];
			end_index_j.low=i;
		}
		else 
			end_index_j.sum+=A[i];
		if (end_index_j.sum>index_j.sum)
			index_j=end_index_j;
	}
	return index_j;
}

int main(){
	msa a;
	int A[100],n;
	cout<<"Enter the no.  of numbers in the array n::";	
	cin>>n;
	cout<<"Enter the numbers\n";
	for(int i=0;i<n;i++)
		cin>>A[i];
	a=FIND_MAXIMUM_SUBARRAY(A,0,n);
	cout<<a.low<<endl<<a.high<<endl<<a.sum<<endl;	
	return 0;
}