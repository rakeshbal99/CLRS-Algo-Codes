#include <iostream>
using namespace std;

typedef struct{
	int low;
	int high;
	int sum;
}msa;
/*typedef struct max_subarray msa*/;   
msa FIND_MAX_CROSSING_SUBARRAY(int A[],int low, int mid ,int high){
	msa a;
	int i,left_sum=-9999999,right_sum=-9999999,sum=0,max_left,max_right;
	for(i=mid;i>=low;i--){
		sum+=A[i];
		if(sum>left_sum){
			left_sum=sum;
			max_left=i;
		}

	}
	sum=0;
	for (i = (mid+1); i <=high; i++)
	{
		sum+=A[i];
		if(sum>right_sum){
			right_sum=sum;
			max_right=i;
		}
	}
	a.low=max_left;
	a.high=max_right;
	a.sum=left_sum+right_sum;
	return a;
}
msa FIND_MAXIMUM_SUBARRAY(int A[],int low,int high){
	msa a,left,right,cross;
	int mid;
	if(high==low){
		a.low=low;
		a.high=high;
		a.sum=A[low];
		return a;
	}
	else{
		mid=(low+high)/2;
		left=FIND_MAXIMUM_SUBARRAY(A,low,mid);
		right=FIND_MAXIMUM_SUBARRAY(A,(mid+1),high);
		cross=FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high);
		if(left.sum>right.sum && left.sum>cross.sum)
			return left;
		else if (right.sum>cross.sum && right.sum>left.sum)
			return right;
		else
			return cross;
	}
}

int main(){
	msa a;
	int A[100],n;
	cout<<"Enter the no.  of numbers in the array :n";	
	cin>>n;
	cout<<"Enter the numbers\n";
	for(int i=0;i<n;i++)
		cin>>A[i];
	a=FIND_MAXIMUM_SUBARRAY(A,0,n);
	cout<<a.low<<endl<<a.high<<endl<<a.sum<<endl;	
	return 0;
}