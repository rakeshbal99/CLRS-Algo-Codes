#include <iostream>
using namespace std;
int heap_size;

void PRINT(int A[],int n){
	for (int i = 1; i <=n; ++i)
		cout<<A[i]<<"  ";
	cout<<endl;
}


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

void BUILD_MAX_HEAP(int A[]){
	for (int i =(heap_size/2); i>=1; i--)
		MAX_HEAPIFY(A,i);
}

void HEAPSORT(int A[],int n){
	
	int temp;
	BUILD_MAX_HEAP(A);
	for (int i=n; i>=2; i--)
	{
		temp=A[1];
		A[1]=A[i];
		A[i]=temp;
		heap_size--;
		MAX_HEAPIFY(A,1);
	}
}

int main(){
	int A[100],n;
	cout<<"Enter the no.  of numbers in the array n::";	
	cin>>n;
	cout<<"Enter the numbers\n";
	for(int i=1;i<=n;i++)
		cin>>A[i];
	heap_size=n;
	HEAPSORT(A,n);
	heap_size=n;
	cout<<"After Sorting we get::: ";
	PRINT(A,heap_size);
	return 0;
}