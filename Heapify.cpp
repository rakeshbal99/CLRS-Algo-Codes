#include <iostream>
using namespace std;
int heap_size;

int PARENT(int i){
	return (i/2);
}

int LEFT(int i){
	return (i*2);
}

int RIGHT(int i){
	return ((2*i)+1);
}
void MAX_HEAPIFY(int A[],int i){
	int l=LEFT(i),t;
	int r=RIGHT(i);
	int largest;
	if(l<=heap_size && A[l]>A[i])
		largest=l;
	else 
		largest=i;
	if (r<=heap_size && A[r]>A[largest])
		largest=r;
	if(largest!=i){
		t=A[largest];
		A[largest]=A[i];
		A[i]=t;
		MAX_HEAPIFY(A,largest);
	}
}

void PRINT(int A[],int n){
	for (int i = 1; i<=n; ++i)
		cout<<A[i]<<"  ";
	cout<<endl;
}

int main(){
	int A[100],n;
	cout<<"Enter the no.  of numbers in the array n::";	
	cin>>n;
	cout<<"Enter the numbers\n";
	for(int i=1;i<=n;i++)
		cin>>A[i];
	cout<<"Before heapifing";
	heap_size=n;
	PRINT(A,heap_size);
	cout<<"Enter the index at the heap needs to be heapified";
	int m;
	cin>>m;
	MAX_HEAPIFY(A,m);
	cout<<"After heapifing";
	PRINT(A,heap_size);
	return 0;
}